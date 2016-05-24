/*
 * Text.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "Text.h"


#include "Author.h"
#include "Quote.h"
#include "../Actions/Context.h"
#include <sstream>
#include <iostream>
#include <list>

Text::Text(int id) {
	this->id = id;
	this->author = -1;
	this->wordCount = 0;
	this->title = "";
}

Text::~Text() {
	// TODO Auto-generated destructor stub
}


int Text::getId() const{
	return this->id;
}

string Text::getTitle() const{
	return this->title;
}

void Text::setTitle(const string& title){
	this->title = title;
}

Author& Text::getAuthor(Context& c){
	return c.getAs().get(author);
}
void Text::setAuthor(const Author& author){
	this->author = author.getId();
}
void Text::setAuthorByFullName(string fullName, Context& c){
	int id = c.getAs().findByFullName(fullName);
	if (id == -1) {
		Author& a = c.getAs().addNew();
		a.setFullName(fullName);
		id = a.getId();
	}
	author = id;
}
void Text::setContent(const string& content){ //TODO Buffer by blocksize, trade space for performance
	this->content.clear();
	istringstream iss(content);
	string w;
	int i = 0;
	sentences.push_back(0);
	while(iss >> w){
		char lc = w[w.size() - 1];
		bool isDot = lc == '.';
		bool isP = (lc == ',' || lc == '.' || lc == ':' || lc == ';');
		if (isP) {
			if(isDot){
				//Register sentence
				sentences.push_back(i + 2); //Skip dot
			}
			this->content.push_back(w.substr(0, w.size() - 1));
			this->content.push_back(w.substr(w.size() - 1, 1));
			i++;
		}else{
			this->content.push_back(w);
			wordCount++;
		}
		i++;
	}
	//sentences.push_back(wordCount + 1); //Sentinel
}
int Text::getWordCount() const{
	return wordCount;
}
int Text::getSentenceCount() const{
	return sentences.size();
}
string Text::getSentenceByIndex(int index) const{ //TODO Idea, use stringbuilder / stream for efficiency
	int start = sentences[index];
	int size = content.size();
	int end = size - 1;
	if(index != end) end = sentences[index + 1];
	string s;
	for(int i = start; i < end; i++){
		s += (i == start ? "" : " ") + content[i];
	}
	return s;
}

void Text::replace(string match, string replace){
	for(unsigned int i = 0; i < content.size(); ++i){
		if(content[i] == match)content[i] = replace;
	}
}
Quote& Text::extractQuote(int from, int to, Context& c){
	Quote& q = c.getQs().addNew();
	q.setTextId(getId(), c);
	q.setStartSentenceIndex(from);
	q.setEndSentenceIndex(to);
	return q;
}
bool Text::matchesWordListAnywhere(string ls, Context& c){
	string lsf = ls.substr(1, ls.size()-2); // Remove {}
	istringstream iss(lsf);
	list<string> l;
	string tmp;
	while(iss >> tmp) l.push_back(tmp);

	istringstream isst(getTitle());
	while(isst >> tmp){
		for(list<string>::iterator it = l.begin(); it != l.end(); ++it){
			if(tmp == (*it))it=l.erase(it);
		}
	}
	if(l.size() == 0)return true;
	for(list<string>::iterator it = l.begin(); it != l.end(); ++it){
		Author& a = getAuthor(c);
		string str = (*it);
		if (a.getName() == str || a.getLastName() == str)it = l.erase(it);
	}
	if(l.size() == 0)return true;
	for(unsigned int i = 0; i < content.size(); ++i){
		for(list<string>::iterator it = l.begin(); it != l.end(); ++it){
			if(content[i] == (*it))it=l.erase(it);
		}
		if(i % 10 == 0 && l.size() == 0)return true;
	}
	return l.size() == 0;
}
void Text::getSentenceListMatchingExpressionEf(string expr, vector<int>& match, vector<string>& cond, bool& c_op, bool root) const{ //pre: Expr != ""
	//Example expr (({casa pilota} & ({rodona} | {quadrat})) | {aigua})
	//1. Analyze expr type. Distinguish andSet from boolExpr
	//[boolExpr]
	bool isExpr = expr[0] == '(';
	string exprf = expr.substr(1, expr.size()-2);
	string tmp;
	istringstream iss(exprf);
	if(!isExpr){ //Treat {} as and cond
		//BoolExpr {word1 word2 word3}
		bool nf = true;
		while(iss >> tmp){
			nf = true;
			for(int i = 0; i < cond.size(); i++)if(cond[i] == tmp)nf = false;
			if(nf)cond.push_back(tmp);
		}
		c_op = true;
		if(root)getSentenceListMatchingWordListInContext(match, cond, c_op, false);
		//cond.clear();
		//assign match
		return;
	}
	//-> Return

	//2. Split into leftExpr and rigtExpr. Parse operator
	bool op; // [false = OR, true = AND]
	bool op_v = false;
	string leftExpr, rightExpr;

	//-- Parse expression parts
	int c = 0;
	bool space = false;
	while(iss >> tmp){
		if(!op_v){
			for(int i = 0; tmp[i] == '('; i++)c++;
			for(int i = tmp.size()-1; tmp[i] == ')'; i--)c--;
		}
		if(c == 0 && !op_v && tmp.length() == 1) {op = tmp == "&"; op_v = true; space = false; continue;}
		if(!op_v)leftExpr += (space ? " " : "") + tmp;
		if(op_v)rightExpr += (space ? " " : "") + tmp;
		space = true;
	}
	//--

	//3. Make recursive calls
	vector<int> match_left, match_right;
	vector<string> cond_left, cond_right;
	bool op_left, op_right;

	getSentenceListMatchingExpressionEf(leftExpr, match, cond_left, op_left, false);
	getSentenceListMatchingExpressionEf(rightExpr, match, cond_right, op_right, false);

	//4. Execute intelligent linear search where operators cannot be combined
	//left
	if(op_left != op || op_right != op){
		//Execute left
		//Do the search and modify match
		getSentenceListMatchingWordListInContext(match, cond_left, op_left, op);
		cond_left.clear();

		//Execute right
		//Do the search and modify match
		getSentenceListMatchingWordListInContext(match, cond_right, op_right, op);
		cond_right.clear();
	}



	//5. Generate cond and c_op to resolve redundant levels
	//cond = cond_left + cond_right
	bool nf = true;
	for(unsigned int i = 0; i < cond_left.size(); i++){
		nf = true;
		for(unsigned int j = 0; j < cond.size(); j++)if(cond_left[i] == cond[j])nf = false;
		if(nf)cond.push_back(cond_left[i]); //No repeat
	}
	for(unsigned int i = 0; i < cond_right.size(); i++){
		nf = true;
		for(unsigned int j = 0; j < cond.size(); j++)if(cond_right[i] == cond[j])nf = false;
		if(nf)cond.push_back(cond_right[i]);
	}

	//6. Execute at root level if necessary
	if(root && op_right == op && op_left == op){
		getSentenceListMatchingWordListInContext(match, cond, op, false); //Or with the context, review
		//cond.clear(); //Not necessary
		return;
	}

	c_op = op;


	//6. Do logic operations based on op to update match
	if(root){

	}
	//	if(op){
	//		for(int i = 0; match_left.size(); i++)
	//			for(int j = 0; match_right.size(); j++){
	//				if(match_left[i] == match_right[j])match.push_back(match_left[i]);
	//			}
	//	}else{
	//		match.insert(match.end(), match_left.begin(), match_left.end());
	//		for(int i = 0; match_right.size(); i++)
	//			for(int j = 0; match.size(); j++){
	//				if(match_right[i] == match[j])match.push_back(match_right[i]);
	//			}
	//	}

	//assign match
}

void Text::checkSentenceForCondition(int i, const vector<string>& cond, bool c_op, vector<string>& remaining) const { //OK
	for (int j = sentences[i]; j < sentences[i + 1]; j++) {
		//match does not contain size sentinel
		//content[j] is a word
		for (unsigned int k = 0; k < remaining.size(); k++) {
			if (content[j] == remaining[k]) {
				remaining.erase(remaining.begin() + k);
				if (!c_op)
					break;

				if (c_op && remaining.size() == 0)
					break; //AND -> Exit when all
			}
		}
	}
}

void Text::getSentenceListMatchingWordListInContext(vector<int>& match, vector<string>& cond, bool c_op, bool m_op) const{ //OK
	//Will always get full match and c_op=AND on first call

	if(m_op){
		//AND
		//Discard sentences
		for(unsigned int i = 0; i < match.size(); i++){
			//Sentence context
			vector<string> remaining(cond);
			checkSentenceForCondition(i, cond, c_op, remaining);
			if((c_op && remaining.size() != 0) || (!c_op && (remaining.size() == cond.size()))){
				for(unsigned int j = 0; j < match.size(); j++){
					if(match[j] == (int)i){
						match.erase(match.begin() + j);
						break;
					}
				}
			}
		}
	}else{
		//OR
		//Add sentences (existing ones are there for sure)
		for(unsigned int i = 0; i < sentences.size() - 1; i++){
			//Sentence context
			//TODO continue if sentence is on match
			vector<string> remaining(cond);
			checkSentenceForCondition(i, cond, c_op, remaining);
			if((c_op && remaining.size() == 0) || (!c_op && remaining.size() < cond.size())){
				bool nf = true;
				for(unsigned int j = 0; j < match.size(); j++){
					if(match[j] == i){
						nf = false;
						break;
					}
				}
				if(nf)match.push_back(i);
			}

		}
	}

}

void Text::getSentenceListMatchingExpression(string expr, vector<int>& match) const{
	vector<string> cond;
 	bool c_op = false;
	//for(unsigned int i = 0; i < sentences.size() - 1; i++)match.push_back(i); //Prepare context for and
 	getSentenceListMatchingExpressionEf(expr, match, cond, c_op, true);
}
//Output section
void Text::printFrequencyTable() const{
	cout << "FrequencyTable" << endl; //TODO
}
void Text::printSentenceListMatchingExpression(string expr) const{
	//for(string sentence : text)if(match
	cout << "All sentences matching " << expr << endl;
	vector<int> match;
	getSentenceListMatchingExpression(expr, match);
	string s;
	for(int m : match) s+= m ;
	for(int m : match)cout << m << endl;
}
void Text::printSentenceListContainingSequence(string sequence) const{
	cout << "All sentences containing " << sequence << endl;
}
void Text::printInfo(Context& c) {
	cout << getAuthor(c).getFullName() << " " << '"' << getTitle() << '"' << endl;
}
void Text::printContent() const{ //TODO treat . elements and special cases
	cout << "Content: " << getTitle();
	cout << content[0];
	for(unsigned int i = 1; i < content.size(); ++i){
		cout << " " << content[i];
	}
}
void Text::printSentenceListInRange(int from, int to){ //pre from < to
	cout << "All sentences from " << from << " to " << to << ": " << endl;
	for(int i = from; i <= to; i++){
		cout << i << " - " << getSentenceByIndex(i) << endl;
	}
}

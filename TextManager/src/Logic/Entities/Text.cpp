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
	while(iss >> w){
		char lc = w[w.size() - 1];
		bool isPoint = lc == '.';
		bool isP = (lc == ',' || lc == '.' || lc == ':' || lc == ';');
		if (isP) {
			if(isPoint){
				//Register sentence
				sentences.push_back(content.size());
			}
			this->content.push_back(w.substr(0, w.size() - 1));
			this->content.push_back(w.substr(w.size() - 1, 1));
		}else{
			this->content.push_back(w);

		}
		wordCount++;
	}
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
void Text::getSentenceListMatchingExpressionEf(string expr, vector<int>& match, vector<string>& cond, bool c_op) const{ //pre: Expr != ""
	//Example expr (({casa pilota} & ({rodona} | {quadrat})) | {aigua})
	//1. Analyze expr type. Distinguish andSet from boolExpr
	//[boolExpr]
	bool isExpr = expr[0] == '(';
	string exprf = expr.substr(1, expr.size()-2);
	string tmp;
	istringstream iss(exprf);
	if(!isExpr){
		//BoolExpr {word1 word2 word3}

		//assign match
		return;
	}
	//-> Return

	//2. Split into leftExpr and rigtExpr. Parse operator
	vector<int> left;
	vector<int> right;
	bool op; // [false = OR, true = AND]
	bool op_v = false;
	string leftExpr, rightExpr;
	int c = 0;
	while(iss >> tmp){
		if(!op_v){
			for(int i = 0; tmp[i] == '('; i++)c++;
			for(int i = tmp.size()-1; tmp[i] == ')'; i--)c--;
		}
		if(c == 0 && !op_v) {op = tmp == "&"; op_v = true;}
		if(!op_v)leftExpr += (c == 0 ? "" : " ") + tmp;
		if(op_v)rightExpr += (c == 0 ? "" : " ") + tmp;
	}

	//3. Make recursive calls
	getSentenceListMatchingExpression(leftExpr, left);
	getSentenceListMatchingExpression(rightExpr, right);

	//4. Do logic operations based on op and assign result to match
	if(op){
		for(int i = 0; left.size(); i++)
			for(int j = 0; right.size(); j++){
				if(left[i] == right[j])match.push_back(left[i]);
			}
	}else{
		match.insert(match.end(), left.begin(), left.end());
		for(int i = 0; right.size(); i++)
			for(int j = 0; match.size(); j++){
				if(right[i] == match[j])match.push_back(right[i]);
			}
	}

	//assign match
}
void Text::getSentenceListMatchingExpression(string expr, vector<int>& match) const{
	vector<string> cond;
	getSentenceListMatchingExpressionEf(expr, match, cond, false);
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

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
#include <functional>

#include <algorithm>
#include <iterator>
using namespace std;
using std::find_if;
using std::list;
using std::set_intersection;

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
		updateFrequencyTable(match, replace);
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
	//Example expr (({casa pilota} & ({rodona} | {quadrat})) | {aigua})
	//1. Analyze expr type. Distinguish andSet from boolExpr
	//[boolExpr]
	bool isExpr = expr[0] == '(';
	string exprf = expr.substr(1, expr.size()-2);
	string tmp;
	istringstream iss(exprf);

	if(!isExpr){ //Treat {} as and cond
		vector<string> cond;
		//BoolExpr {word1 word2 word3}
		bool nf = true;
		while(iss >> tmp){
			nf = true;
			for(int i = 0; i < cond.size(); i++) if(cond[i] == tmp) nf = false;
			if(nf)cond.push_back(tmp);
		}
		getSentenceListMatchingWordListInContext(match, cond, true, false);
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

	getSentenceListMatchingExpression(leftExpr, match_left);
	getSentenceListMatchingExpression(rightExpr, match_right);

	//4. Do logic operations based on op to update match
	sort(match_left.begin(), match_left.end());
	sort(match_right.begin(), match_right.end());
	if(op){
		set_intersection(match_left.begin(), match_left.end(), match_right.begin(), match_right.end(), back_inserter(match));
	}else{
		set_union(match_left.begin(), match_left.end(), match_right.begin(), match_right.end(), back_inserter(match));
	}
}

void Text::calculateFrequencyTable() {
	for(int i = 0; i < content.size(); ++i) {
		vector<pair<string, int>>::iterator it = std::find_if(
					frequencyTable.begin(),
					frequencyTable.end(),
					[&] (pair<string,int> p){return p.first == content[i];}
			);
		if (it != frequencyTable.end()) (*it).second++;
		else{
			if (content[i][0] != '.' and content[i][0] != ',') {
				frequencyTable.push_back(make_pair(content[i], 1));
			}
		}
	}
}

void Text::updateFrequencyTable(string match, string replace){
	vector<pair<string, int>>::iterator itm = std::find_if(
			frequencyTable.begin(),
			frequencyTable.end(),
			[&match] (pair<string,int> p){return p.first == match;}
	);
	(*itm).second--;
	if ((*itm).second == 0) frequencyTable.erase(itm);
	vector<pair<string, int>>::iterator itr = std::find_if(
			frequencyTable.begin(),
			frequencyTable.end(),
			[&replace] (pair<string,int> p){return p.first == replace;}
	);
	if(itr != frequencyTable.end()) (*itr).second++;
	else frequencyTable.push_back(make_pair(replace, 1));
}

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	return ((a.second > b.second) or (a.second == b.second and a.first.size() < b.first.size())
			or (a.second == b.second and a.first.size() == b.first.size() and a.first < b.first));
}

void Text::sortFrequencyTable() {
	sort(frequencyTable.begin(), frequencyTable.end(), compare);
}

//Output section
void Text::printFrequencyTable() {
	for(int i = 0; i < frequencyTable.size(); ++i) {
		cout << frequencyTable[i].first << " " << frequencyTable[i].second << endl;
	}
	cout << endl;
}
void Text::printSentenceListMatchingExpression(string expr) const{
	//for(string sentence : text)if(match
	cout << "All sentences matching " << expr << endl;
	vector<int> match;
	getSentenceListMatchingExpression(expr, match);
	for(int m : match)cout << m + 1 << endl;
}
void Text::printSentenceListContainingSequence(string sequence) const{
	cout << "All sentences containing " << sequence << endl;
}
void Text::printInfo(Context& c) {
	cout << getAuthor(c).getFullName() << " " << '"' << getTitle() << '"' << endl;
}
void Text::printContent(){ //TODO treat . elements and special cases
	int cont = 1;
	for (int i = 0; i < content.size(); i = sentences[i+1]) {
		cout << cont;
		for (int j = i; j < sentences[i+1]; ++j){
			cout << " " << content[j];
		}
		++cont;
		cout << "." << endl;
	}
	cout <<  endl;
}

void Text::printSentenceListInRange(int from, int to){ //pre from < to
	cout << "All sentences from " << from << " to " << to << ": " << endl;
	for(int i = from; i <= to; i++){
		cout << i << " " << getSentenceByIndex(i) << endl;
	}
}

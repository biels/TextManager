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
void Text::setContent(const string& content){ //TODO Buffer by blocksize, trade space for performance
	this->content.clear();
	istringstream iss(content);
	string w;
	while(iss >> w){
		if(w[w.size()-1] == '.'){
			//Register sentence
		}else{
			wordCount++;
		}
		this->content.push_back(w);
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
void Text::getSentenceListMatchingExpression(string expr, vector<int>& match) const{ //pre: Expr != ""
	//Example expr (({casa pilota} & ({rodona} | {quadrat})) | {aigua})
	//1. Analyze expr type. Distinguish andSet from boolExpr
	//[boolExpr]
	bool isExpr = expr[0] == '(';
	if(!isExpr){
		//BoolExpr {word1 word2 word3}

		//assign match
	}
	//-> Return

	//2. Split into leftExpr and rigtExpr. Parse operator
	vector<int> left;
	vector<int> right;
	bool op; // [false = OR, true = AND]
	string leftExpr, rightExpr;

	//3. Make recursive calls
	getSentenceListMatchingExpression(leftExpr, left);
	getSentenceListMatchingExpression(rightExpr, right);

	//4. Do logic operations based on op and assign result to match
	//assign match
}

//Output section
void Text::printFrequencyTable() const{
	cout << "FrequencyTable"; //TODO
}
void Text::printSentenceListMatchingExpression(string expr) const{
	//for(string sentence : text)if(match
	cout << "All sentences matching " << expr;
}
void Text::printSentenceListContainingSequence(string sequence) const{
	cout << "All sentences containing " << sequence;
}
void Text::printInfo(Context& c) const {
	cout << "Info: " << getTitle();
}
void Text::printContent() const{ //TODO treat . elements and special cases
	cout << "Content: " << getTitle();
	cout << content[0];
	for(unsigned int i = 1; i < content.size(); ++i){
		cout << " " << content[i];
	}
}
void Text::printSentenceListInRange(int from, int to){ //pre from < to
	cout << "All sentences from " << from << " to " << to;
	for(unsigned int i = from; i <= to; i++){
		cout << i << " - " << getSentenceByIndex(i);
	}
}

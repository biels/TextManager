/*
 * Text.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "Text.h"
#include "../Actions/Context.h"
#include <sstream>

Text::Text(int id) {
	this->id = id;
	this->author = -1;
	this->title = "";
}

Text::~Text() {
	// TODO Auto-generated destructor stub
}

string Text::getSentenceByIndex(int index) {
	int start = sentences.find(index)->second;
	int size = content.size();
	int end = size - 1;
	if(index != end) end = sentences.find(index + 1)->second;
	string s;
	for(int i = start; i < end; i++){
		s += (i == start ? "" : " ") + content[i];
	}
	return s;
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
		}
		this->content.push_back(w);
	}
}
void Text::replace(string match, string replace){
	for(unsigned int i = 0; i < content.size(); ++i){
		if(content[i] == match)content[i] = replace;
	}
}
void Text::printInfo(Context& c) const {
	cout << "Info: " << getTitle();
}
void Text::printContent(){ //TODO treat . elements and special cases
	cout << "Content: " << getTitle();
	cout << content[0];
	for(unsigned int i = 1; i < content.size(); ++i){
		cout << " " << content[i];
	}
}

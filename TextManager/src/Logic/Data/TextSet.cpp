/*
 * TextSet.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "TextSet.h"
#include "../Actions/Context.h"
TextSet::TextSet() {
	this->lastID = 0;
}

TextSet::~TextSet() {
	// TODO Auto-generated destructor stub
}

int TextSet::getNextID(){
	lastID++;
	return lastID;
}

Text& TextSet::addNew(){
	Text t(getNextID());
	add(t);
	return get(t.getId());
}

void TextSet::add(const Text& t) {//allow copy ?
	texts.insert(make_pair(t.getId(), t));
}

void TextSet::remove(int id) {
	texts.erase(texts.find(id));
}
void TextSet::remove(const Text& t){
	this->remove(t.getId());
}

bool TextSet::exists(int id) {
	return texts.find(id) != texts.end();
}

Text& TextSet::get(int id){
	return (*texts.find(id)).second;
}

int TextSet::findByTitle(string title) const{
	for(pair<int, Text> p : texts){
		Text t = p.second;
		if (t.getTitle() == title) return t.getId();
	}
	return -1;
}

void TextSet::printAllByAuthor(int id, Context& c) const{
	for(map<int, Text>::const_iterator it = texts.begin(); it != texts.end(); ++it) {
		Text t = (*it).second;
		if (t.getAuthor(c).getId() == id) {
			t.printInfo(c); //Print what=?
		}
	}
}

void TextSet::printAll(Context& c) const{ //Print what?
	for(map<int, Text>::const_iterator it = texts.begin(); it != texts.end(); ++it) {
		(*it).second.printInfo(c);
	}
}


/*
 * TextSet.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "TextSet.h"

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
	m.insert(make_pair(t.getId(), t));
}

void TextSet::remove(int id) {
	m.erase(m.find(id));
}
void TextSet::remove(const Text& t){
	this->remove(t.getId());
}

bool TextSet::exists(int id) {
	return m.find(id) != m.end();
}

Text& TextSet::get(int id){
	return (*m.find(id)).second;
}

int TextSet::findByTitle(string title) {
	for(pair<int, Text> p : m){
		Text t = p.second;
		if (t.getTitle() == title)return t.getId();
	}
	return -1;
}

TextSet TextSet::getAllByAuthor(int id) {

}

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

int TextSet::getNextID() const {
	++lastID;
	return lastID;
}

void TextSet::add(const Text& t) {

}

void TextSet::remove(int id) {

}

void TextSet::removeByQuote(const Quote& q) {

}

bool TextSet::exists(int id) {
	return m.find(id) != m.end();
}

Text TextSet::get(int id) {

}

Text TextSet::getByTitle(string t) {

}

TextSet TextSet::getAllByAuthor(int id) {

}

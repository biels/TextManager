/*
 * Text.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "Text.h"

Text::Text(int id) {
	// TODO Auto-generated constructor stub

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

int Text::getAuthor() const{
	return this->author;
}

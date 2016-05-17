/*
 * Quote.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "Quote.h"

Quote::Quote(int id) {
	// TODO Auto-generated constructor stub
	this->ID = id;
}

Quote::~Quote() {
	// TODO Auto-generated destructor stub
}

int Quote::getID() const {
	return ID;
}

int Quote::getAuthorID const {
	return authorID;
}

void Quote::setAuthorID(int autId) {
	authorID = autID;
}

int Quote::getStartIndex const {
	return StartIndex;
}

int Quote::getEndIndex() const {
	return EndIndex;
}

string Quote::getUniqueIdentifier(Author a) const {
	string id;
	id[0] = a.name()[0];
	id[1] = a.lastName[0];
	//id[2] = a.id 			TODO és l'id d'aquell autor?
	return s;
}


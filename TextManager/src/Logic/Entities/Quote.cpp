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

int Quote::getTextID const {
	return textID;
}

void Quote::setTextID(int id) {
	textID = id;
}

int Quote::getStartIndex const {
	return StartIndex;
}

int Quote::getEndIndex() const {
	return EndIndex;
}

string Quote::getUniqueIdentifier(Context& c) const {
	string s = c.getAs().get(authorID).getInitials();
	int id = c.getNextQuoteID();
	s += id;
	//id[2] = a.id		TODO és l'id d'aquell autor?
	return s;
}

void Quote::print(int id, Context& c) {
	cout << getUniqueIdentifier(c) << endl;

}



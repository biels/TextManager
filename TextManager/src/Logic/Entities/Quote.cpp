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

int Quote::getTextID() const {
	return textID;
}

void Quote::setTextID(int id) {
	textID = id;
}

int Quote::getQuoteNumber() {
	return quoteNumber;
}

string Quote::getUniqueIdentifier(Context& c) const {
	string s = c.getTs().get(textID).getAuthor(c).getInitials();
	int id = c.getNextQuoteID();
	s += id;
	//id[2] = a.id		TODO és l'id d'aquell autor?
	return s;
}

void Quote::print(Context& c) {
	cout << getUniqueIdentifier(c) << endl;
	Text& t = c.getTs().get(textID);
	for(int i = startSentenceIndex; i <= endSentenceIndex; ++i) {
		cout << i << " " << t.getSentenceByIndex(i) << endl;
	}
}



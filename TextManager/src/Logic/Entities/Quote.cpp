/*
 * Quote.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "Quote.h"

#include "../Actions/Context.h"

Quote::Quote(int id) {
	textID = -1;
	startSentenceIndex = 0;
	endSentenceIndex = 0;
	this->ID = id;
}

Quote::~Quote() {
	// TODO Auto-generated destructor stub
}

int Quote::getId() const {
	return ID;
}

int Quote::getTextID() const {
	return textID;
}

Text& Quote::getText(Context& c){
	return c.getTs().get(textID);
}

void Quote::setTextID(int id) {
	textID = id;
}

int Quote::getQuoteNumber() {
	return quoteNumber;
}

int Quote::getStartIndex() const {
	return startSentenceIndex;
}

int Quote::getEndIndex() const {
	return endSentenceIndex;
}

string Quote::getUniqueIdentifier(Context& c) const {
	string s = c.getTs().get(textID).getAuthor(c).getInitials();
	int id = c.getNextQuoteID();
	s += id;
	//id[2] = a.id		TODO és l'id d'aquell autor?
	return s;
}

void Quote::printQuote(Context& c) {
	cout << getUniqueIdentifier(c) << endl;
	Text& t = c.getTs().get(textID);
	for(int i = startSentenceIndex; i <= endSentenceIndex; ++i) {
		cout << i << " " << t.getSentenceByIndex(i) << endl;
	}
}



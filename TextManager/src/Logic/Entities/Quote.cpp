/*
 * Quote.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "Quote.h"

#include "../Actions/Context.h"
#include "../Entities/Text.h"

Quote::Quote(int id) {
	quoteNumber = -1;
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

int Quote::getTextId() const {
	return textID;
}
void Quote::updateReference(Context& c){
	string s = "IN";// c.getTs().get(textID).getAuthor(c).getInitials();
	s += getQuoteNumber();
	//id[2] = a.id		TODO és l'id d'aquell autor?
	ref = s;
}
Text& Quote::getText(Context& c){
	return c.getTs().get(textID);
}
Author& Quote::getAuthor(Context& c){
	return getText(c).getAuthor(c);
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

string Quote::getUniqueIdentifier() const {
	return ref;
}

int Quote::getEndSentenceIndex() const {
	return endSentenceIndex;
}

void Quote::setEndSentenceIndex(int endSentenceIndex) {
	this->endSentenceIndex = endSentenceIndex;
}

int Quote::getStartSentenceIndex() const {
	return startSentenceIndex;
}

void Quote::setStartSentenceIndex(int startSentenceIndex) {
	this->startSentenceIndex = startSentenceIndex;
}

void Quote::setQuoteNumber(int quoteNumber) {
	this->quoteNumber = quoteNumber;
}

void Quote::setTextId(int textId, Context& c) {
	textID = textId;
	updateReference(c);
}

//Output zone
void Quote::print(Context& c) const{
	cout << getUniqueIdentifier() << endl;
	Text& t = c.getTs().get(textID);
	for(int i = startSentenceIndex; i <= endSentenceIndex; ++i) {
		cout << i << " " << t.getSentenceByIndex(i) << endl;
	}
}
void Quote::printInfo(Context& c) const {
	cout << getUniqueIdentifier() << endl;
}


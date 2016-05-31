/*
 * Quote.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "Quote.h"

#include <sstream>
#include "../Actions/Context.h"
#include "../Entities/Text.h"
#include "../Entities/Author.h"

Quote::Quote(int id) {
	quoteNumber = -1;
	textID = -1;
	startSentenceIndex = 0;
	endSentenceIndex = 0;
	this->ID = id;
}

Quote::~Quote() {

}

int Quote::getId() const {
	return ID;
}

int Quote::getTextId() const {
	return textID;
}
void Quote::updateReference(Context& c){
	stringstream ss, ss2;
	ss << c.getTs().get(textID).getAuthor(c).getInitials();
	ss << getQuoteNumber();
	ss >> ref;
	//Update header
	header0 = getAuthor(c).getName();
	ss2 << '"' << getText(c).getTitle() << '"';
	getline(ss2, header1);
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
	setQuoteNumber(c.getQs().getNextQuoteNumber(getAuthor(c).getInitials()));
	updateReference(c);
}

void Quote::updateContent(Context& c) {
	Text& t = c.getTs().get(textID);
	content.clear();
	for(int i = startSentenceIndex - 1; i <= endSentenceIndex - 1; ++i) {
		content.push_back(t.getSentenceByIndex(i));
	}
}

//Output zone
void Quote::print(bool withTextHeader, bool withAuthor) const{
	cout << getUniqueIdentifier() << endl;
	for(int i = 0; i <= endSentenceIndex - startSentenceIndex; ++i) {
		cout << i + startSentenceIndex  << " " << content[i] << endl;
	}
	if(withTextHeader){
			if(withAuthor)cout << header0 << " ";
			cout << header1;
			cout << endl;
	}
}
void Quote::printInfo() const {
	cout << header0 << " " << header1 << endl;
	cout << startSentenceIndex << "-" << endSentenceIndex << endl;
	for(int i = 0; i <= endSentenceIndex - startSentenceIndex; ++i) {
		cout << i + startSentenceIndex  << " " << content[i] << endl;
	}
}



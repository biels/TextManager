/*
 * QuoteSet.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "QuoteSet.h"
#include "../Actions/Context.h"
#include "../Entities/Quote.h"
#include "../Entities/Text.h"
#include "../Entities/Author.h"
QuoteSet::QuoteSet() {
	lastID = 0;
}

QuoteSet::~QuoteSet() {

}

int QuoteSet::getNextID() {
	++lastID;
	return lastID;
}
int QuoteSet::getNextQuoteNumber(string initials){
	map<string, int>::iterator it = lastQuoteNumberMap.find(initials);
	if(it == lastQuoteNumberMap.end()){
		lastQuoteNumberMap.insert(make_pair(initials, 1));
		return 1;
	}
	it->second++;
	return it->second;
}

void QuoteSet::add(const Quote& q) {
	quotes.insert(make_pair(q.getId(), q));
}

Quote& QuoteSet::addNew() {
	Quote q(getNextID());
	add(q);
	return get(q.getId());
}

void QuoteSet::remove(int id) {
	quotes.erase(quotes.find(id));
}

void QuoteSet::remove(const Quote& q) {
	remove(q.getId());
}

bool QuoteSet::exists(int id) const {
	return quotes.find(id) != quotes.end();
}

Quote& QuoteSet::get(int id) {
	return (*quotes.find(id)).second;
}
int QuoteSet::findByRef(string ref) { //TODO MAP LINEAR SEARCH WITHOUT COPYING
	for (map<int, Quote>::const_iterator it = quotes.begin(); it != quotes.end(); it++){
		Quote q = (*it).second;
		if(q.getUniqueIdentifier() == ref)return q.getId();
	}
	return -1;
}
void QuoteSet::printAll(Context& c) const{
	for (map<int, Quote>::const_iterator it = quotes.begin(); it != quotes.end(); it++){
		Quote q = (*it).second;
		q.print(c);
	}
}
void QuoteSet::printAllByAuthor(int id, Context& c) const{
	for (map<int, Quote>::const_iterator it = quotes.begin(); it != quotes.end(); it++){
		Quote q = (*it).second;
		if (q.getAuthor(c).getId() == id) {
			q.print(c);
		}
	}
}

void QuoteSet::printAllByText(int id, Context& c) const{
	for (map<int, Quote>::const_iterator it = quotes.begin(); it != quotes.end(); it++){
		Quote q = (*it).second;
		if (q.getText(c).getId() == id) {
			q.print(c);
		}
	}
}

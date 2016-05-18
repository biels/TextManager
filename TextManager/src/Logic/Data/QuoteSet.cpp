/*
 * QuoteSet.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "QuoteSet.h"
#include "../Actions/Context.h"
QuoteSet::QuoteSet() {
	lastID = 0;
}

QuoteSet::~QuoteSet() {
}

int QuoteSet::getNextID() const {
	++lastID;
	return lastID;
}

void QuoteSet::add(const Quote& q) {
	m.insert(make_pair(q.getId(), q));
}

Quote& QuoteSet::addNew() {
	Quote q(getNextID());
	add(q);
	return (get.q.getID());
}

void QuoteSet::removeByID(int id) {
	m.erase(m.find(id));
}

void QuoteSet::removeByQuote(const Quote& q) {
	m.erase(m.find(q));
}

bool QuoteSet::exists(int id) const {
	return m.find(id) != m.end();
}

Quote& QuoteSet::get(int id) const {
	return (*m.find(id)).second;
}

void QuoteSet::printAllByAuthor(int id, Context& c) {
	for (map<int, Quote>::iterator it = m.begin(); it != m.end(); it++){
		Quote q = (*it).second;
		if (q.authorID == id) {
			q.print(id, c);
		}
	}
}

void QuoteSet::printAllByText(int id) {

}

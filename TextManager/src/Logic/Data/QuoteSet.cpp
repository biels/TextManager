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

int QuoteSet::getNextID() {
	++lastID;
	return lastID;
}

void QuoteSet::add(const Quote& q) {
	m.insert(make_pair(q.getId(), q));
}

Quote& QuoteSet::addNew() {
	Quote q(getNextID());
	add(q);
	return get(q.getId());
}

void QuoteSet::remove(int id) {
	m.erase(m.find(id));
}

void QuoteSet::remove(const Quote& q) {
	remove(q.getId());
}

bool QuoteSet::exists(int id) const {
	return m.find(id) != m.end();
}

Quote& QuoteSet::get(int id) {
	return (*m.find(id)).second;
}
void QuoteSet::printAll(Context& c) const{
	for (map<int, Quote>::const_iterator it = m.begin(); it != m.end(); it++){
		Quote q = (*it).second;
		q.print(c);
	}
}
void QuoteSet::printAllByAuthor(int id, Context& c) const{
	for (map<int, Quote>::const_iterator it = m.begin(); it != m.end(); it++){
		Quote q = (*it).second;
		if (q.getAuthor(c).getId() == id) {
			q.print(c);
		}
	}
}

void QuoteSet::printAllByText(int id, Context& c) const{
	for (map<int, Quote>::const_iterator it = m.begin(); it != m.end(); it++){
		Quote q = (*it).second;
		if (q.getText(c).getId() == id) {
			q.print(c);
		}
	}
}

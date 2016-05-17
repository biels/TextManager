/*
 * QuoteSet.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "QuoteSet.h"

QuoteSet::QuoteSet() {
}

QuoteSet::~QuoteSet() {
}

int QuoteSet::getNextID() const {
	++lastID;
	return lastID;
}

void QuoteSet::add(const Quote& q) {

}

Quote QuoteSet::addNew() {

}

void QuoteSet::removeByID(int id) {

}

void QuoteSet::removeByQuote(const Quote& q) {

}

bool QuoteSet::exists(int id) const {

}

Quote QuoteSet::get(int id) const {

}

void QuoteSet::getAllByAuthor(int id) {

}

void QuoteSet::getAllByText(int id) {

}

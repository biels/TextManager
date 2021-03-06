/*
 * QuoteSet.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "QuoteSet.h"

#include <algorithm>
#include <utility>

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

bool QuoteSet::exists(int startIndex, int endIndex, int textId) const{
	for (map<int, Quote>::const_iterator it = quotes.begin(); it != quotes.end(); it++){
		Quote q = (*it).second;
		if(q.getStartSentenceIndex() == startIndex && q.getEndSentenceIndex() == endIndex && q.getTextId() == textId)return true;
	}
	return false;
}

Quote& QuoteSet::get(int id) {
	return (*quotes.find(id)).second;
}
int QuoteSet::findByRef(string ref) const {
	for (map<int, Quote>::const_iterator it = quotes.begin(); it != quotes.end(); it++){
		Quote q = (*it).second;
		if(q.getUniqueIdentifier() == ref)return q.getId();
	}
	return -1;
}
bool sortQuotes(string a, string b){
	return a < b;
}
void QuoteSet::printAll(Context& c){
	vector<string> result;
	for (map<int, Quote>::const_iterator it = quotes.begin(); it != quotes.end(); it++){
		Quote q = (*it).second;
		result.push_back(q.getUniqueIdentifier());
	}
	sort(result.begin(), result.end(), sortQuotes);
	for(int i = 0; i < result.size(); i++){
		int id = findByRef(result[i]);
		if(id != -1){
			Quote q = get(id);
			q.print(true, true);
		}
	}
}
void QuoteSet::printAllByAuthor(int id, Context& c) {
	vector<string> result;
	for (map<int, Quote>::const_iterator it = quotes.begin(); it != quotes.end(); it++){
		Quote q = (*it).second;
		if (q.getAuthor(c).getId() == id)result.push_back(q.getUniqueIdentifier());
	}
	sort(result.begin(), result.end(), sortQuotes);
	for(int i = 0; i < result.size(); i++){
		int id = findByRef(result[i]);
		if(id != -1){
			Quote q = get(id);
			q.print(true, false);

		}
	}
}

void QuoteSet::printAllByText(int id, bool associated, Context& c){
	vector<string> result;
	for (map<int, Quote>::const_iterator it = quotes.begin(); it != quotes.end(); it++){
		Quote q = (*it).second;
		if (q.getText(c).getId() == id) {
			result.push_back(q.getUniqueIdentifier());
		}
	}
	sort(result.begin(), result.end(), sortQuotes);
	for(int i = 0; i < result.size(); i++){
		int id = findByRef(result[i]);
		if(id != -1){
			Quote q = get(id);
			q.print(!associated, true);
		}
	}

}

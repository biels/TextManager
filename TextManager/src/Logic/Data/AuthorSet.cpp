/*
 * AuthorSet.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "AuthorSet.h"
#include "../Actions/Context.h"
#include "../Entities/Author.h"
#include <iostream>
#include <sstream>
AuthorSet::AuthorSet() {
	lastID = 0;
}

AuthorSet::~AuthorSet() {
	// TODO Auto-generated destructor stub
}

int AuthorSet::getNextID(){
	lastID++;
	return lastID;
}
Author& AuthorSet::addNew(){
	Author a(getNextID());
	add(a);
	return get(a.getId());
}

void AuthorSet::add(const Author& a){
	authors.insert(make_pair(a.getId(), a));
}

void AuthorSet::remove(int id){
	authors.erase(authors.find(id));
}

void AuthorSet::remove(const Author& a){
	this->remove(a.getId());
}

bool AuthorSet::exists(int id){
	return authors.find(id) != authors.end();
}

Author& AuthorSet::get(int id){
	return (*authors.find(id)).second;
}

int AuthorSet::findByFullName (string name) {
	for(map<int, Author>::const_iterator it = authors.begin(); it != authors.end(); ++it) {
		const std::pair<const int, Author> p = *it;
		if(p.second.getName() == name)return p.first;
	}
	return -1;
}

void AuthorSet::printAuthorList(Context& c) {
	vector<string> output;
	for(map<int, Author>::const_iterator it = authors.begin(); it != authors.end(); ++it) {
		string out = "";
		stringstream ss;
		Author a = (*it).second;
		a.print();
		int id = a.getId();
<<<<<<< HEAD
		ss << " " << c.getTs().numberTextsAuthor(id, c);
		ss << " " << c.getTs().numberSentencesAuthorTexts(id, c);
		ss << " " << c.getTs().numberWordsAuthorTexts(id, c);
=======
		cout << " " << c.getTs().numberTextsAuthor(id, c);
		cout << " " << c.getTs().numberSentencesAuthorTexts(id, c)-1;
		cout << " " << c.getTs().numberWordsAuthorTexts(id, c) << endl;
>>>>>>> branch 'master' of https://github.com/biels/TextManager.git
	}
	sort(output.begin(), output.end());
	for(int i = 0; i < output.size(); i++)cout << output[i] << endl;
}

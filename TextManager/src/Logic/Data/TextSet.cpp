/*
 * TextSet.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "TextSet.h"

#include <sstream>
#include <algorithm>

#include "../Actions/Context.h"
#include "../Entities/Text.h"
#include "../Entities/Quote.h"
#include "../Entities/Author.h"
TextSet::TextSet() {
	this->lastID = 0;
}

TextSet::~TextSet() {
	// TODO Auto-generated destructor stub
}

int TextSet::getNextID(){
	lastID++;
	return lastID;
}

Text& TextSet::addNew(){
	Text t(getNextID());
	add(t);
	return get(t.getId());
}

void TextSet::add(const Text& t) {//allow copy ?
	texts.insert(make_pair(t.getId(), t));
}

void TextSet::remove(int id, Context& c) {
	map<int, Text>::iterator t = texts.find(id);
	int authorId = (*t).second.getAuthor(c).getId();
	texts.erase(t);
//	bool used = false;
//	for(pair<int, Text> p : texts){
//		if(p.second.getAuthor(c).getId() == authorId){
//			used = true;
//			break;
//		}
//	}
//	if(!used){
//		c.getAs().remove(authorId);
//	}
}
void TextSet::remove(const Text& t, Context& c){
	this->remove(t.getId(), c);
}

bool TextSet::exists(int id) {
	return texts.find(id) != texts.end() ;
}

Text& TextSet::get(int id){
	return (*texts.find(id)).second;
}

int TextSet::countAllWithAuthor(int id, Context& c){
	int cnt = 0;
	for(pair<int, Text> p : texts){
		Text& t = p.second;
		if (t.getAuthor(c).getId() == id)cnt++;
	}
	return cnt;
}

int TextSet::findByTitle(string title) const{
	for(pair<int, Text> p : texts){
		Text& t = p.second;
		if (t.getTitle() == title) return t.getId();
	}
	return -1;
}
int TextSet::findByWordList(string list, Context& c){ // if more than one, return -1
	int found = -1;
	for(pair<int, Text> p : texts){
		Text& t = p.second;
		if(t.matchesWordListAnywhere(list, c)){
			if(found != -1)return -1;
			found = t.getId();
		}
	}
	return found;
}


int TextSet::numberWordsAuthorTexts(int id, Context& c) const {
	int words = 0;
	for(map<int, Text>::const_iterator it = texts.begin(); it != texts.end(); ++it) {
		Text t = (*it).second;
		if (t.getAuthor(c).getId() == id) words += t.getWordCount();
	}
	return words;
}

int TextSet::numberSentencesAuthorTexts(int id, Context& c) const{
	int sent = 0;
	for(map<int, Text>::const_iterator it = texts.begin(); it != texts.end(); ++it) {
		Text t = (*it).second;
		if (t.getAuthor(c).getId() == id) sent += t.getSentenceCount();
	}
	return sent;
}

int TextSet::numberTextsAuthor(int id, Context& c) const{
	int ntexts = 0;
	for(map<int, Text>::const_iterator it = texts.begin(); it != texts.end(); ++it) {
		Text t = (*it).second;
		if (t.getAuthor(c).getId() == id) ++ntexts;
	}
	return ntexts;
}

bool TextSet::textAlreadyExists (const string& title, const string& autor, Context& c) const {
	bool titleIs = false;
	map<int, Text>::const_iterator it = texts.begin();
	while (it != texts.end() and !titleIs) {
		Text t = (*it).second;
		if (t.getTitle() == title) {
			titleIs = true;
			if (t.getAuthor(c).getName() == autor) return true;
		}
		++it;
	}
	return false;
}

void TextSet::printAllByAuthor(int id, Context& c){
	vector<string> output;
	for(map<int, Text>::iterator it = texts.begin(); it != texts.end(); ++it) {
		Text& t = (*it).second;
		if (t.getAuthor(c).getId() == id) {
			string out = t.getTitle();
			output.push_back(out);
		}
	}
	sort(output.begin(), output.end());
	for(int i = 0; i < output.size(); i++){
		cout << '"' << output[i] << '"' << endl;
	}
}

void TextSet::printAll(Context& c) {
	vector<string> output;
	for(map<int, Text>::iterator it = texts.begin(); it != texts.end(); ++it) {
		Text& t = (*it).second;
		output.push_back(t.getAuthor(c).getName() + " " + '"' + t.getTitle() + '"');
	}
	sort(output.begin(), output.end());
	for(int i = 0; i < output.size(); i++)cout << output[i] << endl;
}


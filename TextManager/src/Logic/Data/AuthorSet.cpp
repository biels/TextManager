/*
 * AuthorSet.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "AuthorSet.h"

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
Author AuthorSet::addNew(){
	Author a(getNextID());
	add(a);
	return get(a.getId());
}

void AuthorSet::add(const Author& a){
	m.insert(make_pair(a.getId(), a));
}

void AuthorSet::remove(int id){
	m.erase(m.find(id));
}
void AuthorSet::remove(const Author& a){
	this->remove(a.getId());
}
bool AuthorSet::exists(int id){
	return m.find(id) != m.end();
}
const Author& AuthorSet::get(int id) const{
	return (*m.find(id)).second;
}

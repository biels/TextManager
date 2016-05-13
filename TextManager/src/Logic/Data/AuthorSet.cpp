/*
 * AuthorSet.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "AuthorSet.h"

AuthorSet::AuthorSet() {
	// TODO Auto-generated constructor stub

}

AuthorSet::~AuthorSet() {
	// TODO Auto-generated destructor stub
}

void AuthorSet::add(Author a){
	//m.insert(make_pair(a.getId(), a));
}

void AuthorSet::remove(int id){
	//m.erase(m.find(id));
}
void AuthorSet::remove(Author a){
	//remove(a.getId());
}
bool AuthorSet::exists(int id){
	return m.find(id) != m.end();
}
Author AuthorSet::get(int id){
	//return *m.find(id);
}

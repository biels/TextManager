/*
 * Author.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "Author.h"

Author::Author(int id) {
	this->id = id;

}

Author::~Author() {

}

int Author::getId(){
	return this->id;
}
string Author::getName() const{
	return this->name;
}
void Author::setName(const string& name){
	this->name = name;
}
string Author::getLastName() const{
	return this->lastName;
}
void Author::setLastName(const string& lastName){
	this->lastName = lastName;
}
string Author::getInitials() const{
	return toupper(getName()[0]) + "" + toupper(getLastName()[0]);
}

/*
 * Author.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "Author.h"
#include "sstream"

Author::Author(int id) {
	this->id = id;

}

Author::~Author() {

}

int Author::getId() const{
	return this->id;
}
const string& Author::getName() const{
	return this->name;
}
void Author::setName(const string& name){
	this->name = name;
}
const string& Author::getLastName() const{
	return this->lastName;
}
void Author::setLastName(const string& lastName){
	this->lastName = lastName;
}
void Author::setFullName(const string& fullName){
	istringstream iss("");
	iss >> this->name;
	iss >> this->lastName;
}
string Author::getInitials() const{
	return toupper(getName()[0]) + "" + toupper(getLastName()[0]);
}

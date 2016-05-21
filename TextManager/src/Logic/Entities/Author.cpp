/*
 * Author.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "Author.h"
#include "../Actions/Context.h"
#include "sstream"
#include <iostream>

Author::Author(int id) {
	this->id = id;
}

Author::~Author() {
}

int Author::getId() const{
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
void Author::setFullName(const string& fullName){
	istringstream iss(fullName);
	iss >> this->name;
	iss >> this->lastName;
}
string Author::getInitials() const{
	if(getName().length() == 0 || getLastName().length() == 0)return "--";
	return toupper(getName()[0]) + "" + toupper(getLastName()[0]); //cppshell try
}

void Author::print() const{
	//TODO Check outpu format
	cout << getName() << " " << getLastName();
}

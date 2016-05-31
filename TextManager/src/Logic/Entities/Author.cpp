/*
 * Author.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#include "Author.h"
#include "../Actions/Context.h"
#include <sstream>
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
void Author::setName(const string name){
	istringstream iss(name);
	string tmp;
	iss >> this->name;
	this->initials = name[0];
	while(iss >> tmp){
		this->name += " " + tmp;
		this->initials += tmp[0];
	}
}
void Author::print() const{
	//TODO Check outpu format
	cout << getName() << endl;
}
string Author::getInitials() const{
	return this->initials;
}

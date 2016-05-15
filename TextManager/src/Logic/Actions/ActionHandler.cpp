/*
 * ActionHandler.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "ActionHandler.h"

ActionHandler::ActionHandler(){

}

ActionHandler::~ActionHandler() {

}

void ActionHandler::afegirText(string titol, string autor, string contingut){
	Text t = ts.addNew();
	t.setTitle(titol);
	Author a = as.addNew();
	a.setName(autor); //spilt first and last name
	t.setAuthor(a);
	//Set constent
	cout << "Text afegit";
}
void ActionHandler::triarText(string s){
	int id = ts.findByTitle(s);
	if (id != -1) {
		cout << "Text triat: " << chosenTextID;
	}else{
		cout << "No s'ha tobat cap text amb el títol especificat";
	}
}

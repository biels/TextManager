/*
 * ActionHandler.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "ActionHandler.h"
#include "Context.h"
ActionHandler::ActionHandler(){

}

ActionHandler::~ActionHandler() {

}

void ActionHandler::afegirText(string titol, string autor, string contingut){
	Text& t = c.getTs().addNew();
	t.setTitle(titol);

	Author& a = c.getAs().addNew();
	a.setFullName(autor); //spilt first and last name
	t.setAuthor(a);

	t.setContent(contingut);
	//Set constent
	cout << "Text afegit" << endl;
}
void ActionHandler::triarText(string titol){
	int id = c.getTs().findByTitle(titol);
	if (id != -1) {
		cout << "Text triat: " << c.getChosenTextId();
	}else{
		cout << "No s'ha tobat cap text amb el títol especificat";
	}
}
void ActionHandler::eliminarText(){
	c.getTs().remove(c.getChosenTextId());
}

void ActionHandler::substitueix(string match, string replace){
	Text& t = c.getTs().get(c.getChosenTextId());
	t.replace(match, replace);
	cout << "Replaced";
}
void ActionHandler::textosAutor (string autor){
	//c.getTs().printAllByAuthor(c.getAs().findByName(autor), c);
}
void ActionHandler::textos(){
	//c.getTs().printAll(c);
}
void ActionHandler::autors(){
	//c.getAs().printAuthorList();
}
void ActionHandler::info(){

}

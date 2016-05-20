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
		c.setChosenTextId(id);
		cout << "Text triat: " << c.getChosenTextId() << endl;
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
	c.getTs().printAllByAuthor(c.getAs().findByName(autor), c);
}
void ActionHandler::textos(){
	c.getTs().printAll(c);
}
void ActionHandler::autors(){
	c.getAs().printAuthorList();
}
void ActionHandler::info(){
	c.getChosenText().printInfo(c);
}
void ActionHandler::autor(){
	c.getChosenText().getAuthor(c).print();
}
void ActionHandler::contingut(){
	c.getChosenText().printContent();
}
void ActionHandler::frases(int x, int y){
	c.getChosenText().printSentenceListInRange(x, y);
}
void ActionHandler::nombreFrases(){
	cout << c.getChosenText().getSentenceCount();
}
void ActionHandler::nombreParaules(){
	cout << c.getChosenText().getWordCount();
}
void ActionHandler::taulaFrequencies(){
	c.getChosenText().printFrequencyTable();
}
void ActionHandler::frasesSequencia(string seq){
	c.getChosenText().printSentenceListContaining(seq);
}
void ActionHandler::frasesExpressio(string exp){
	c.getChosenText().printSentenceListMatchingExpression(exp);
}

void ActionHandler::afegirCita(int x, int y){
	c.getChosenText().
}

void ActionHandler::infoCita(string ref){

}

void ActionHandler::CitesAutor(string nom){
	c.getQs().printAllByAuthor(c.getAs().findByName(nom), c);
}

void ActionHandler::cites(){

}

void ActionHandler::totesCites(){
	c.getQs().printAll(c);
}

void ActionHandler::eliminarCita(string ref){
	c.getQs().remove(c.getQs().findByRef(ref));
}

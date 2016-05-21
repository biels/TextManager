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

	cout << "Text afegit" << endl;
}
void ActionHandler::triarText(string seq){
	int id = c.getTs().findByWordList(seq, c);
	c.setChosenTextId(id);
	if (id != -1) {
		cout << "Text triat: " << c.getChosenTextId() << endl;
	}else{
		cout << "No s'ha tobat cap text amb la seqüència especificada" << endl;
	}
}
void ActionHandler::eliminarText(){
	if(!c.existsChosenText()){cout << "error"; return;}
	c.getTs().remove(c.getChosenTextId());
	//TODO Remove author as well in some cases
}

void ActionHandler::substitueix(string match, string replace){
	if(!c.existsChosenText()){cout << "error"; return;}
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
	if(!c.existsChosenText()){cout << "error"; return;}
	c.getChosenText().printInfo(c);
}
void ActionHandler::autor(){
	if(!c.existsChosenText()){cout << "error"; return;}
	c.getChosenText().getAuthor(c).print();
}
void ActionHandler::contingut(){
	if(!c.existsChosenText()){cout << "error"; return;}
	c.getChosenText().printContent();
}
void ActionHandler::frases(int x, int y){
	if(!c.existsChosenText()){cout << "error"; return;}
	c.getChosenText().printSentenceListInRange(x, y);
}
void ActionHandler::nombreFrases(){
	if(!c.existsChosenText()){cout << "error"; return;}
	cout << c.getChosenText().getSentenceCount();
}
void ActionHandler::nombreParaules(){
	if(!c.existsChosenText()){cout << "error"; return;}
	cout << c.getChosenText().getWordCount();
}
void ActionHandler::taulaFrequencies(){
	if(!c.existsChosenText()){cout << "error"; return;}
	c.getChosenText().printFrequencyTable();
}
void ActionHandler::frasesSequencia(string seq){
	if(!c.existsChosenText()){cout << "error"; return;}
	c.getChosenText().printSentenceListContainingSequence(seq);
}
void ActionHandler::frasesExpressio(string exp){
	if(!c.existsChosenText()){cout << "error"; return;}
	c.getChosenText().printSentenceListMatchingExpression(exp);
}

void ActionHandler::afegirCita(int x, int y){
	if(!c.existsChosenText()){cout << "error"; return;}
	c.getChosenText().extractQuote(x, y, c);
}

void ActionHandler::infoCita(string ref){
	c.getQs().get(c.getQs().findByRef(ref)).printInfo(c);
}

void ActionHandler::citesAutor(string nom){
	c.getQs().printAllByAuthor(c.getAs().findByName(nom), c);
}

void ActionHandler::cites(){
	if(!c.existsChosenText()){cout << "error"; return;}
	c.getQs().printAllByText(c.getChosenTextId(), c);
}

void ActionHandler::totesCites(){
	c.getQs().printAll(c);
}

void ActionHandler::eliminarCita(string ref){
	c.getQs().remove(c.getQs().findByRef(ref));
}

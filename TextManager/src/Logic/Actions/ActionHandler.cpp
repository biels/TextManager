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
	t.setAuthorByFullName(autor, c);
	t.setContent(contingut);
	cout << "afegir text " << '"' << titol << '"' << endl;
	cout << endl;
}
void ActionHandler::triarText(string seq){
	int id = c.getTs().findByWordList(seq, c);
	c.setChosenTextId(id);
	if (id != -1) {
		cout << "triar text " << seq << endl;
	}
	cout << endl;
}
void ActionHandler::eliminarText(){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	c.getTs().remove(c.getChosenTextId(), c);
	c.setChosenTextId(-1);
	//TODO Remove author as well in some cases
}

void ActionHandler::substitueix(string match, string replace){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	Text& t = c.getTs().get(c.getChosenTextId());
	t.replace(match, replace);
	cout << "Replaced";
}
void ActionHandler::textosAutor (string autor){
	c.getTs().printAllByAuthor(c.getAs().findByFullName(autor), c);
	cout << endl;
}
void ActionHandler::textos(){ //TODO Imprimeix desordenat
	c.getTs().printAll(c);
	cout << endl;
}
void ActionHandler::autors(){
	c.getAs().printAuthorList(c);
	cout << endl;
}
void ActionHandler::info(){ //TODO no fa cout de l'error
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	cout << "info ?" << endl;
	c.getChosenText().printInfo(c, true);
	cout << endl;
}
void ActionHandler::autor(){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	c.getChosenText().getAuthor(c).print();
	cout << endl;
}
void ActionHandler::contingut(){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	cout << "contingut ?" << endl;
	c.getChosenText().printContent();
	cout << endl;
}
void ActionHandler::frases(int x, int y){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	c.getChosenText().printSentenceListInRange(x, y);
	cout << endl;
}

void ActionHandler::nombreFrases(){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	cout << c.getChosenText().getSentenceCount() << endl;
}
void ActionHandler::nombreParaules(){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	cout << c.getChosenText().getWordCount();
	cout << endl;
}
void ActionHandler::taulaFrequencies(){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	c.getChosenText().printFrequencyTable();
	cout << endl;
}
void ActionHandler::frasesSequencia(string seq){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	c.getChosenText().printSentenceListContainingSequence(seq);
	cout << endl;
}
void ActionHandler::frasesExpressio(string exp){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	c.getChosenText().printSentenceListMatchingExpression(exp);
	cout << endl;
}

void ActionHandler::afegirCita(int x, int y){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	c.getChosenText().extractQuote(x, y, c);
	cout << endl;
}

void ActionHandler::infoCita(string ref){
	c.getQs().get(c.getQs().findByRef(ref)).printInfo(c);
}

void ActionHandler::citesAutor(string nom){
	c.getQs().printAllByAuthor(c.getAs().findByFullName(nom), c);
}

void ActionHandler::cites(){
	if(!c.existsChosenText()){cout << "error" << endl; return;}
	c.getQs().printAllByText(c.getChosenTextId(), c);
}

void ActionHandler::totesCites(){
	c.getQs().printAll(c);
}

void ActionHandler::eliminarCita(string ref){
	c.getQs().remove(c.getQs().findByRef(ref));
}
Context& ActionHandler::exposeContext(){
	return c;
}

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
}

void ActionHandler::triarText(string seq){
	int id = c.getTs().findByWordList(seq, c);
	c.setChosenTextId(id);
	if (id == -1){printError(); return;}

}

void ActionHandler::eliminarText(){
	if(!c.existsChosenText()){printError(); return;}
	c.getTs().remove(c.getChosenTextId(), c);
	c.setChosenTextId(-1);
	//TODO Remove author as well in some cases
}

void ActionHandler::substitueix(string match, string replace){
	if(!c.existsChosenText()){printError(); return;}
	Text& t = c.getTs().get(c.getChosenTextId());
	t.replace(match, replace);
}

void ActionHandler::textosAutor (string autor){
	c.getTs().printAllByAuthor(c.getAs().findByFullName(autor), c);
}

void ActionHandler::textos(){
	c.getTs().printAll(c);

}

void ActionHandler::autors(){
	c.getAs().printAuthorList(c);
}

void ActionHandler::info(){
	if(!c.existsChosenText()){printError(); return;}
	c.getChosenText().printInfo(c, true);

}

void ActionHandler::autor(){
	if(!c.existsChosenText()){printError(); return;}
	c.getChosenText().getAuthor(c).print();

}

void ActionHandler::contingut(){
	if(!c.existsChosenText()){printError(); return;}
	c.getChosenText().printContent();

}

void ActionHandler::frases(int x, int y){
	if(!c.existsChosenText()){printError(); return;}
	c.getChosenText().printSentenceListInRange(x, y);

}

void ActionHandler::nombreFrases(){
	if(!c.existsChosenText()){printError(); return;}
	cout << c.getChosenText().getSentenceCount() << endl;

}

void ActionHandler::nombreParaules(){
	if(!c.existsChosenText()){printError(); return;}
	cout << c.getChosenText().getWordCount() << endl;

}

void ActionHandler::taulaFrequencies(){
	if(!c.existsChosenText()){printError(); return;}
	c.getChosenText().printFrequencyTable();

}

void ActionHandler::frasesSequencia(string seq){
	if(!c.existsChosenText()){printError(); return;}
	c.getChosenText().printSentenceListContainingSequence(seq);

}

void ActionHandler::frasesExpressio(string exp){
	if(!c.existsChosenText()){printError(); return;}
	c.getChosenText().printSentenceListMatchingExpression(exp);

}

void ActionHandler::afegirCita(int x, int y){
	if(!c.existsChosenText()){printError(); return;}
	int sc = c.getChosenText().getSentenceCount();
	if (x > sc || y > sc){printError(); return;} //Print error ?
	c.getChosenText().extractQuote(x, y, c);

}

void ActionHandler::infoCita(string ref){
	c.getQs().get(c.getQs().findByRef(ref)).printInfo();

}

void ActionHandler::citesAutor(string nom){
	c.getQs().printAllByAuthor(c.getAs().findByFullName(nom), c);

}

void ActionHandler::cites(){
	if(!c.existsChosenText()){printError(); return;}
	c.getQs().printAllByText(c.getChosenTextId(), false, c);

}

void ActionHandler::totesCites(){
	c.getQs().printAll(c);

}

void ActionHandler::eliminarCita(string ref){
	int id = c.getQs().findByRef(ref);
	if (id == -1) {printError(); return;}
	c.getQs().remove(id);
}

void ActionHandler::printError() {
	cout << "error" << endl;
}

Context& ActionHandler::exposeContext(){
	return c;
}

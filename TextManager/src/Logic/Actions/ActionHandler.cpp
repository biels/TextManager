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
	if (id == -1){cout << "error" << endl << endl; return;}
	cout << "triar text " << seq << endl;
	cout << endl;
}

void ActionHandler::eliminarText(){
	cout << "eliminar text" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	c.getTs().remove(c.getChosenTextId(), c);
	c.setChosenTextId(-1);
	//TODO Remove author as well in some cases
}

void ActionHandler::substitueix(string match, string replace){
	cout << "substitueix " << '"' << match << '"' << " per " << '"' << replace << '"' << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	Text& t = c.getTs().get(c.getChosenTextId());
	t.replace(match, replace);
	cout << endl;
}

void ActionHandler::textosAutor (string autor){
	cout << "textos autor " << '"' << autor << '"' << endl;
	c.getTs().printAllByAuthor(c.getAs().findByFullName(autor), c);
	cout << endl;
}

void ActionHandler::textos(){
	cout << "tots textos ?" << endl;
	c.getTs().printAll(c);
	cout << endl;
}

void ActionHandler::autors(){
	cout << "tots autors ?" << endl;
	c.getAs().printAuthorList(c);
	cout << endl;
}

void ActionHandler::info(){
	cout << "info ?" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	c.getChosenText().printInfo(c, true);
	cout << endl;
}

void ActionHandler::autor(){
	cout << "autor ?" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	c.getChosenText().getAuthor(c).print();
	cout << endl;
}

void ActionHandler::contingut(){
	cout << "contingut ?" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	c.getChosenText().printContent();
	cout << endl;
}

void ActionHandler::frases(int x, int y){
	cout << "frases " << x << " " << y << " ?" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	c.getChosenText().printSentenceListInRange(x, y);
	cout << endl;
}

void ActionHandler::nombreFrases(){
	cout << "nombre de frases ?" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	cout << c.getChosenText().getSentenceCount() << endl;
	cout << endl;
}

void ActionHandler::nombreParaules(){
	cout << "nombre de paraules ?" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	cout << c.getChosenText().getWordCount();
	cout << endl;
}

void ActionHandler::taulaFrequencies(){
	cout << "taula de frequencies ?" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	c.getChosenText().printFrequencyTable();
	cout << endl;
}

void ActionHandler::frasesSequencia(string seq){
	cout << "frases " << '"' << seq << '"' << " ?" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	c.getChosenText().printSentenceListContainingSequence(seq);
	cout << endl;
}

void ActionHandler::frasesExpressio(string exp){
	cout << "frases " << "{" << exp << "}" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	c.getChosenText().printSentenceListMatchingExpression(exp);
	cout << endl;
}

void ActionHandler::afegirCita(int x, int y){
	cout << "afegir cita " << x << " " << y << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	c.getChosenText().extractQuote(x, y, c);
	cout << endl;
}

void ActionHandler::infoCita(string ref){
	cout << "info cita " << '"' << ref << '"' << " ?" << endl;
	c.getQs().get(c.getQs().findByRef(ref)).printInfo(c);
	cout << endl;
}

void ActionHandler::citesAutor(string nom){
	cout << "cites autor " << '"' << nom << '"' << " ?" << endl;
	c.getQs().printAllByAuthor(c.getAs().findByFullName(nom), c);
	cout << endl;
}

void ActionHandler::cites(){
	cout << "cites ?" << endl;
	if(!c.existsChosenText()){cout << "error" << endl << endl; return;}
	c.getQs().printAllByText(c.getChosenTextId(), c);
	cout << endl;
}

void ActionHandler::totesCites(){
	cout << "totes cites ?" << endl;
	c.getQs().printAll(c);
	cout << endl;
}

void ActionHandler::eliminarCita(string ref){
	cout << "eliminar cita " << '"' << ref << '"' << endl;
	c.getQs().remove(c.getQs().findByRef(ref));
	cout << endl;
}

Context& ActionHandler::exposeContext(){
	return c;
}

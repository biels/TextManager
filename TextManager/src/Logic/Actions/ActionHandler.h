/*
 * ActionHandler.h
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#ifndef LOGIC_ACTIONS_ACTIONHANDLER_H_
#define LOGIC_ACTIONS_ACTIONHANDLER_H_

#include "../Data/TextSet.h"

class ActionHandler {
private:
	TextSet s;
public:
	ActionHandler();
	virtual ~ActionHandler();
	//Texts
	void afegirText(string titol, string autor, string contingut);
	void triarText(vector<string>);
	void eliminarText(string text);
	void subtitueix(string match, string replace);
	void textosAutor (string autor);
	void textos();
	void autors();
	void info();
	string autor();
	void contingut();
	void frases(int x, int y);
	int nombreFrases();
	int nombreParaules();
	void taulaFrequencies();
	void frasesExpressio(string exp);
	void frasesSequencia();
	//Quotes

};

#endif /* LOGIC_ACTIONS_ACTIONHANDLER_H_ */

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
	//!!!FALTA DOCUMENTAR!!!
	//Aquí aniria bé documentar exactament cada funció
	//amb la descripció del pdf de la pràctica
	//Molt provisional
	//Texts
	void afegirText(string titol, string autor, string contingut);
	void triarText(vector<string> words);
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

/*
 * ActionHandler.h
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#ifndef LOGIC_ACTIONS_ACTIONHANDLER_H_
#define LOGIC_ACTIONS_ACTIONHANDLER_H_

#include "../Data/TextSet.h"
/**
 * @class ActionHandler
 * @brief Gestiona totes les possibles interaccions amb el sistema.
 * Aquesta classe s'encarrega únicament de la interacció amb el sistema de manera conceptual.
 */
class ActionHandler {
private:
	TextSet s;
public:
	ActionHandler();
	virtual ~ActionHandler();
	//-!!!FALTA DOCUMENTAR!!!
	//Aquí aniria bé documentar exactament cada funció
	//amb la descripció del pdf de la pràctica
	//Molt provisional
	//Texts

	/*! Afegeix un text al sistema.
	 *
	 * @param titol El títol del text
	 * @param autor L'autor del text
	 * @param contingut El contingut del text, paraula per paraula
	 */
	void afegirText(string titol, string autor, vector<string> contingut);

	/**
	 *
	 * @param words
	 */
	void triarText(vector<string> words);

	/**@brief Elimina el text seleccionat del sistema
	 * \pre Hi ha un text seleccionat
	 * \post El text seleccionat s'ha eliminat. A partir d'aquest moment i fins la propera execució correcta de la funció triarText, es considera que no existeix un últim text triat.
	 */
	void eliminarText();
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

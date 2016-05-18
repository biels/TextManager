/*
 * ActionHandler.h
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#ifndef LOGIC_ACTIONS_ACTIONHANDLER_H_
#define LOGIC_ACTIONS_ACTIONHANDLER_H_

#include "Context.h"
#include "../Data/TextSet.h"
#include "../Data/AuthorSet.h"
#include "../Data/QuoteSet.h"
#include "../Entities/Author.h"
#include "../Entities/Quote.h"
#include "../Entities/Text.h"

#include <iostream>

/**
 * @class ActionHandler
 * @brief Gestiona totes les possibles interaccions amb el sistema.
 * Aquesta classe s'encarrega únicament de la interacció amb el sistema de manera conceptual.
 */
class ActionHandler {
private:
	Context c;
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
	void afegirText(string titol, string autor, string contingut);

	/**
	 *
	 * @param words
	 */
	void triarText(string s);

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
	void cites();
	void citesAutor();
	void totesCites();
	void eliminarCita();
};

#endif /* LOGIC_ACTIONS_ACTIONHANDLER_H_ */

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
	void triarText(string titol);

	/**@brief Elimina el text seleccionat del sistema
	 * \pre Hi ha un text seleccionat
	 * \post El text seleccionat s'ha eliminat. A partir d'aquest moment i fins la propera execució correcta de la funció triarText, es considera que no existeix un últim text triat.
	 */
	void eliminarText();

	void substitueix(string match, string replace);

	void textosAutor (string autor);
	void textos();
	void autors();
	/**
	 * @brief Mostra informació de l'últim text triat
	 * (autor, títol, nombre de frases, nombre de paraules i cites associades)
	 */
	void info();
	/**
	 * @brief Mostra l'autor de l'últim text triat.
	 */
	void autor();
	/**@brief mostra el contingut de l'ultim text triat
	 * Amb les seves frases numerades a partir de l'1.
	 * Per mostrar una frase, s'escriura el numero de frase seguit d'un espai i de la frase, amb un unic salt de lnia al nal d'aquesta.
	 * En el format de sortida, els signes de puntuacio aniran enganxats a la paraula previa i no hi haura ni tabuladors ni dos espais seguits.
	 */
	void contingut();
	/**@brief Mostra les frases entre la x-esima i la y-esima del contingut de l'ultim text triat
	 * extrems inclosos (si x = y, no es repeteix la frase). Aquesta comanda requereix un interval valid de frases, es a dir, que 1  x  y  n, on n es el nombre total de frases.
	 * @param x x-èssima frase
	 * @param y y-èssima frase
	 */
	void frases(int x, int y);
	/**@brief Mostra el nombre de frases del contingut de l'ultim text triat.
	 */
	void nombreFrases();
	/**@brief Mostra el nombre de paraules del contingut de l'ultim text triat.
	 */
	void nombreParaules();
	/**@brief mostra totes les paraules del contingut del text ordenades decreixentment per frequencia
	 * (per a cada paraula la cadena que la representa i la seva frequencia) de l'ultim text triat.
	 * En cas d'empat de frequencia les paraules s'ordenen creixement, primer per llargada i despres alfabeticament.
	 */
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

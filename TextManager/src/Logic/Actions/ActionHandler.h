/*
ª * ActionHandler.h
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

	/**
	 * @brief Imprimeix per pantalla error
	 * \pre Ha hagut un error
	 * \post El resultat és l'impressió de la paraula error per pantalla
	 */
	void printError();

public:
	/**
	 * @brief Creadora per defecte
	 * \pre Cert
	 * \post El resultat és un ActionHandler nou
	 */
	ActionHandler();

	/**
	 * @brief Destructora per defecte
	 */
	virtual ~ActionHandler();

	/**
	 * @brief Afegeix un text al sistema.
	 * \pre El text no és al sistema.
	 * \post El text és ara al sistema.
	 * @param titol El títol del text
	 * @param autor L'autor del text
	 * @param contingut El contingut del text, paraula per paraula
	 */
	void afegirText(string titol, string autor, string contingut);

	/**
	 * @brief Tria un text del sistema
	 *	\pre Cert
	 *	\post Selecciona que conté les paraules dins la seqüència seq. En cas de que més d'un tezxt compleixi aquesta condició, el text seleccionat deixa d'existir.
	 * @param titol Títol del text
	 */
	void triarText(string seq);

	/**
	 * @brief Elimina l'últim el text seleccionat del sistema
	 * \pre Hi ha un text seleccionat
	 * \post El text seleccionat s'ha eliminat. A partir d'aquest moment i fins la propera execució correcta de la funció triarText, es considera que no existeix un últim text triat.
	 */
	void eliminarText();

	/**
	 * @brief Canvia totes les aparicions de la primera paraula per la segona en l'últim text triat.
	 *	\pre Hi ha un text seleccionat
	 *	\post El text es el mateix però on hi havia "match" ara hi és "replace".
	 *	@param match paraula que es substituirà
	 *	@param replace paraula que substituirà a match
	 */
	void substitueix(string match, string replace);

	/**
	 * @brief Mostra els textos d’un determinat autor
	 *	\pre Cert
	 *	\post El resultat és tots els títols dels textos de l'autor.
	 *	@param autor
	 */
	void textosAutor (string autor);

	/**
	 * @brief Mostra tots els textos emmagatzemats en el sistema
	 * \pre Cert
	 * \post El resultat són tots els textos ordenats per autor i després per títol.
	 */
	void textos();

	/**
	 * @brief Mostra tots els autors amb textos en el sistema
	 * \pre Cert
	 * \post El resultat és tots els autors amb textos. Per cada autor es diu el
		nombre de textos que hi consten, el nombre total de frases i de paraules del
		contingut dels seus textos
	 */
	void autors();

	/**
	 * @brief Mostra informació de l'últim text triat
	 * \pre Hi ha un text seleccionat
	 * \post El resultat és l'autor, el títol, el nombre de frases, el nombre de paraules i les cites associades de l'últim text triat.
	 */
	void info();

	/**
	 * @brief Mostra l'autor de l'últim text triat.
	 * \pre Hi ha un text seleccionat
	 * \post El resultat és l'autor de l'últim text triat
	 */
	void autor();

	/**
	 * @brief mostra el contingut de l'ultim text triat
	 * Amb les seves frases numerades a partir de l'1.
	 * Per mostrar una frase, s'escriura el numero de frase seguit d'un espai i de la frase, amb un unic salt de lnia al nal d'aquesta.
	 * En el format de sortida, els signes de puntuacio aniran enganxats a la paraula previa i no hi haura ni tabuladors ni dos espais seguits.
	 */
	void contingut();

	/**
	 * @brief Mostra les frases entre la x-esima i la y-esima del contingut de l'ultim text triat
	 * extrems inclosos (si x = y, no es repeteix la frase). Aquesta comanda requereix un interval valid de frases, es a dir, que 1  x  y  n, on n es el nombre total de frases.
	 * @param x x-èsima frase
	 * @param y y-èsima frase
	 */
	void frases(int x, int y);

	/**
	 * @brief Mostra el nombre de frases del contingut de l'ultim text triat.
	 * \pre Hi ha un text seleccionat
	 * \post El resultat és el número de frases de l'últim text triat
	 */
	void nombreFrases();

	/**
	 * @brief Mostra el nombre de paraules del contingut de l'ultim text triat.
	 * \pre Hi ha un text seleccionat
	 * \post El resultat és el número de paraules de l'últim text triat
	 */
	void nombreParaules();

	/**
	 * @brief mostra totes les paraules del contingut del text ordenades decreixentment per freqüència
	 * \pre Hi ha un text seleccionat
	 * \post El resultat és totes les paraules del text, ordenat decreixentment per freqüència de l'últim text triat. En cas d'empat de freqüència, les paraules s'ordenen creixement, primer per llargada i després alfabèticament.
	 */
	void taulaFrequencies();

	/**
	 * @brief Mostra les frases del contingut de l’últim text triat que compleixen l’expressió
	 * \pre Hi ha un text seleccionat
	 * \post El resultat és, per cada frase que cumpleixi exp, el seu número i el seu contingut, ordenades creixentment pel seu número
	 * @param exp expressió que han de cumplir les frases
	 */
	void frasesExpressio(string exp);

	/**
	 * @brief Mostra les frases on apareix la seqüència de paraules
	 * \pre Hi ha un text seleccionat
	 * \post El resultat és les frases on hi apareix seq.
	 * @param seq sequüència de paraules que han de tenir les frases
	 */
	void frasesSequencia(string seq);

	/**
	 * @brief Afegeix una cita al sistema
	 * \pre Hi ha un text seleccionat i 1 ≤ x ≤ y ≤ n, on n és el nombre total de frases
	 * \post S'ha afegir una una cita al sistema basada en les frases que van de la x-èsima a la y-èsima del contingut de l’últim text triat.
	 * @param x x-èssima frase
	 * @param y y-èssima frase
	 */
	void afegirCita (int x, int y);

	/**
	 * @brief Mostra informació d’una cita
	 * \pre Cert
	 * \post El resultat és l'autor, el títol, el número de la frase inicial i número de la frase final i el contingut de la frase o frases que la componen amb referència ref.
	 * @param ref referència de la cita
	 */
	void infoCita(string ref);

	/**
	 * @brief Mostra totes les cites d’un determinat autor
	 * \pre Cert
	 * \post El resultat és totes les cites, cadascuna amb la seva referència, el contingut de les frases i títol del text d’on provenen ordenades per referència de l'autor amb nom name.
	 * @param name Nom de l'autor de les cites que es volen saber
	 */
	void citesAutor(string name);

	/**
	 * @brief Mostra totes les cites d'un text
	 * \pre Hi ha un text seleccionat
	 * \post El resultat és totes les cites de l'últim text triat, cadascuna amb la seva referència, el contingut de les frases i títol del text d’on provenen ordenades per referència
	 */
	void cites();

	/**
	 * @brief Mostra totes les cites del sistema
	 * \pre Cert
	 * \post El resultat és totes les cites del sistema, cadascuna amb la seva referència, el contingut de les frases, l'autor i el títol del text d'on provenen
	 */
	void totesCites();

	/**
	 * @brief Elimina una cita del sistema
	 * \pre Cert
	 * \post S'ha eliminat la cita amb referència ref del sistema
	 * @param referència de la cita que es vol eliminar
	 */
	void eliminarCita(string uid);


	//TEST ZONE - WILL BE REMOVED
	Context& exposeContext();
};

#endif /* LOGIC_ACTIONS_ACTIONHANDLER_H_ */

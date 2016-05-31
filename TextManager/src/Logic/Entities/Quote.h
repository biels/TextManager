/*
 * Quote.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_ENTITIES_QUOTE_H_
#define LOGIC_ENTITIES_QUOTE_H_

#include <iostream>
#include <string>
#include <vector>

class Context;
class Author;
class Text;

using namespace std;

/** @class Quote
 * 	@brief Representa una frase o més consecutives d'un text.
 */

class Quote {
private:
	int ID, quoteNumber,textID, startSentenceIndex, endSentenceIndex;
	string ref;
	string header0, header1;
	vector<string> content;
	void updateReference(Context& c);

public:
	/** @brief Creadora per defecte.
	 * \pre Cert.
	 * \post Crea una cita, especificant l'identificador.
	 */
	Quote(int id);

	virtual ~Quote();

	/** @brief Mostra l'identificador de la cita.
	 * \pre Cert.
	 * \post El resultat és l'identificador del paràmetre implícit.
	 */
	int getId() const;

	/** @brief Mostra l'identificador de l'autor de la cita.
	 * \pre El paràmetre implícit conté la referència a un autor vàlid.
	 * \post El resultat és l'identificador de l'autor del paràmetre implícit.
	 */
	int getTextId() const;

	/**
	 * @brief Retorna un text
	 * \pre Cert
	 * \post El resultat és el text al que pertany la cita
	 */
	Text& getText(Context& c);

	/**
	 * @brief Retorna un autor
	 * \pre Cert
	 * \post El resultat és l'autor al que pertany la cita
	 */
	Author& getAuthor(Context& c);

	/**
	 * @brief Retorna l'identificador de cita
	 * \pre Cert
	 * \post El resultat és l'identificador associat a la cita
	 */
	int getQuoteNumber();

	/** @brief Estableix l'identificador de l'autor de la cita.
	 *	\pre Cert.
	 *	\post id és l'identificador de l'autor del paràmetre implícit.
	 */
	void setTextId(int textId, Context& c);

	/** @brief Mostra la posició relativa al text on comença la cita.
	 * 	\pre Cert.
	 * 	\post El resultat és l'índex on comença la cita.
	 */
	int getStartIndex() const;

	/**	@brief Mostra la posició relativa al text on acaba la cita.
	 * 	\pre Cert.
	 * 	\post El resultat és l'índex on acaba el la cita.
	 */
	int getEndIndex() const;

	/** @brief Mostra la cadena que identifica exclusivament aquesta cita. Aquesta està fromada per les inicials i un nombre auto incremental.
	 *	\pre El paràmetre implícit conté la referència a un autor vàlid.
	 *	\post El resultat és l'identificador complet de la cita.
	 */
	string getUniqueIdentifier() const;

	/**
	 * @brief Retorna el número on acaba la frase
	 * \pre Cert
	 * \post El resultat és la posició en el contingut del text on acaba la frase
	 */
	int getEndSentenceIndex() const;

	/**
	 * @brief Estableix el número on acaba la frase
	 * \pre La frase no té identificador d'acabament
	 * \post S'ha afegit la posició on acaba la frase en contingut
	 * @param endSentenceIndex número que diu en quina posició acaba la frase
	 */
	void setEndSentenceIndex(int endSentenceIndex);

	/**
	 * @brief Retorna el número on comença la frase
	 * \pre Cert
	 * \post El resultat és la posició en el contingut del text on comença la frase
	*/
	int getStartSentenceIndex() const;

	/**
	 * @brief Estableix el número on comença la frase
	 * \pre La frase no té identificador d'inici
	 * \post S'ha afegit la posició on comença la frase en contingut
	 * @param endSentenceIndex número que diu en quina posició comença la frase
	*/
	void setStartSentenceIndex(int startSentenceIndex);

	/**
	 * @brief Estableix identificador a la cita
	 * \pre La cita no té identificador
	 * \post El resultat és la cita amb el seu identificador corresponent
	 * @param quoteNumber identificador de la cita
	 */
	void setQuoteNumber(int quoteNumber);

	/**
	 * @brief Actualitza el vector on es guarden les frases
	 * \pre El vector no té totes les frases del text
	 * \post El resultat és el vector actualitzat amb totes les frases
	 */
	void updateContent(Context& c);

	//Output zone
	/**
	 * @brief Imprimeix informació de la cita
	 * \pre Cert
	 * \post Imprimeix les cites, i, depenent del valor dels booleans el títol i l'autor del text al que pertanyen
	 * @param withTextHeader si és cert, s'imprimeix el títol del text
	 * @param withAuthor si és cert, s'imprimeix l'autor de la cita
	 */
	void print(bool withTextHeader, bool withAuthor) const;

	/**
	 * @brief Imprimeix la informació de la cita
	 * \pre Cert
	 * \post El resultat és l'autor, el títol del text, l'identificador de les cites, i les cites.
	 */
	void printInfo() const;
};

#endif /* LOGIC_ENTITIES_QUOTE_H_ */

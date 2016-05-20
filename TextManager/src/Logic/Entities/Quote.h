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
#include "Text.h"

using namespace std;

/** @class Quote
 * 	@brief Representa una frase o més consecutives d'un text.
 */
class Quote {
private:
	int ID, quoteNumber,textID, startSentenceIndex, endSentenceIndex;
	string ref;
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

	Text& getText(Context& c);

	Author& getAuthor(Context& c);

	int getQuoteNumber();


	/** @brief Estableix l'identificador de l'autor de la cita.
	 *	\pre Cert.
	 *	\post id és l'identificador de l'autor del paràmetre implícit.
	 */
	void setTextI(int id);

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



	int getEndSentenceIndex() const;
	void setEndSentenceIndex(int endSentenceIndex);
	int getStartSentenceIndex() const;
	void setStartSentenceIndex(int startSentenceIndex);
	void setTextId(int textId);
	void setQuoteNumber(int quoteNumber, Context& c);

	//Output zone
	void print(Context& c)	const;

	void printInfo(Context& c) const;
};

#endif /* LOGIC_ENTITIES_QUOTE_H_ */

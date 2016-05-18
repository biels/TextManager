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

using namespace std;

/** @class Quote
 * 	@brief Representa una frase o més consecutives d'un text.
 */
class Quote {
private:
	int ID, authorID, startSentenceIndex, endSentenceIndex;

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
	int getID();

	/** @brief Mostra l'identificador de l'autor de la cita.
	 * \pre El paràmetre implícit conté la referència a un autor vàlid.
	 * \post El resultat és l'identificador de l'autor del paràmetre implícit.
	 */
	int getAuthorID();

	/** @brief Estableix l'identificador de l'autor de la cita.
	 *	\pre Cert.
	 *	\post identificator és l'identificador de l'autor del paràmetre implícit.
	 */
	void setAuthorID(int identificator);

	/** @brief Mostra la posició relativa al text on comença la cita.
	 * 	\pre Cert.
	 * 	\post El resultat és l'índex on comença la cita.
	 */
	int getStartIndex();

	/**	@brief Mostra la posició relativa al text on acaba la cita.
	 * 	\pre Cert.
	 * 	\post El resultat és l'índex on acaba el la cita.
	 */
	int getEndIndex();

	/** @brief Mostra la cadena que identifica exclusivament aquesta cita. Aquesta està fromada per les inicials i un nombre auto incremental.
	 *	\pre El paràmetre implícit conté la referència a un autor vàlid.
	 *	\post El resultat és l'identificador complet de la cita.
	 */
	string getUniqueIdentifier(Author a);

	void print();
};

#endif /* LOGIC_ENTITIES_QUOTE_H_ */

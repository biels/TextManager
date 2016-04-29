/*
 * Quote.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_ENTITIES_QUOTE_H_
#define LOGIC_ENTITIES_QUOTE_H_

/** @class Quote
 * 	@brief Representa una frase o més consecutives d'un text.
 */
class Quote {
private:
	int ID, authorID, startIndex, endIndex;

public:
	/** @brief Creadora per defecte.
	 * \pre Cert.
	 * \post Crea una cita sense codi d'dentificació, ni autor ni índexs.
	 */
	Quote();

	virtual ~Quote();

	/** @brief Mostra l'identificador de la cita.
	  * \pre Cert.
	  * \post El resultat és l'identificador del paràmetre implícit.
	*/
	int getID();

	/** @brief Mostra l'identificador de l'autor de la cita.
	 * \pre Cert.
	 * \post El resultat és l'identificador de l'autor del paràmetre implícit.
	 */
	int getAuthorID();

	/** @rief Estableix l'dentificador de l'autor de la cita.
	 *	\pre Cert
	 *	\post identificator és l'identificador de l'autor del paràmetre implícit.
	 */
	void setAuthorID(int identificator);

	/** @brief Mostra l'índex on comença la cita.
	 * 	\pre Cert.
	 * 	\post El resultat és l'índex on comença el paràmetre implícit.
	 */
	int getStartIndex();

	/**	@brief Mostra l'índex on acaba la cita.
	 * 	\pre Cert.
	 * 	\post El resultat és l'índex on acaba el paràmetre implícit.
	 */
	int getEndIndex();

	/** @brief Mostra l'identificador de l'autor amb les inicials i l'identificador numèric.
	 *	\pre Cert.
	 *	\post El resultat és l'identificador complet de la cita.
	 */
	string getUniqueIdentifier()

};

#endif /* LOGIC_ENTITIES_QUOTE_H_ */

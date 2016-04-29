/*
 * Author.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_ENTITIES_AUTHOR_H_
#define LOGIC_ENTITIES_AUTHOR_H_

/** @class Author
 * @brief És una seqüència de paraules que conté nom i cognom d'una sola persona.
 */

class Author {
private:
	string name, lastname;

public:
	/** @brief Creadora per defecte
	 * \pre Cert
	 * \post El resultat és un autor sense nom ni cognom.
	 */
	Author();

	virtual ~Author();

	/** @brief Mostra les inicials de l'autor per crear la referència de l'autor.
	 * \pre Cert
	 * \post Retorna les incial de l'autor
	 */
	string getInitials();
};

#endif /* LOGIC_ENTITIES_AUTHOR_H_ */

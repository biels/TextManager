/*
 * Author.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_ENTITIES_AUTHOR_H_
#define LOGIC_ENTITIES_AUTHOR_H_

//#include "../Actions/Context.h"
#include <string>

using namespace std;

/** @class Author
 *  @brief Representa un autor, una seqüència de paraules que conté el nom i el cognom d'una sola persona.
 */

class Author {
private:
	int id;
	string name;
	string initials;

public:
	/** @brief Crea un autor amb l'identificador especificat.
	 * \pre Cert.
	 * \post El resultat és un autor amb l'identificador especificat sense nom ni cognom.
	 */
	Author(int id);

	virtual ~Author();

	/**@brief Mostra l'identificador de l'autor
	 * \pre Cert.
	 * \post El resultat és l'identificador del paràmetre implícit.
	 */
	int getId() const;

	/** @brief Mostra el nom de l'autor.
	 *  \pre Cert.
	 *  \post El resultat és el nom del paràmetre implícit.
	 */
	string getName() const;

	/** @brief Estableix el nom de l'autor.
	 *  \pre Cert.
	 *  \post name és el nom del paràmetre implícit.
	 *  @param name nom de l'autor
	 */
	void setName(const string name);

	/** @brief Mostra les inicials de l'autor
	 * \pre S'han utilitzat amb èxit les accions setName() i setLastName() del paràmetre implícit. @see setName() @see setLastName()
	 * \post Retorna les incials del paràmtre implícit.
	 */
	string getInitials() const;

	/**
	 * @brief Imprimeix un autor
	 * \post Cert
	 * \pre El resultat és el nom i el cognom de l'autor
	 */
	void print() const;
};

#endif /* LOGIC_ENTITIES_AUTHOR_H_ */

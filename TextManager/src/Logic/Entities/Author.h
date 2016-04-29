/*
 * Author.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_ENTITIES_AUTHOR_H_
#define LOGIC_ENTITIES_AUTHOR_H_
#include <string>
using namespace std;
/** @class Author
 *  @brief Representa una seqüència de paraules que conté nom i cognom d'una sola persona.
 */

class Author {
private:
	string name;
	string lastname;

public:
	/** @brief Creadora per defecte.
	 * \pre Cert.
	 * \post El resultat és un autor sense nom ni cognom.
	 */
	Author();

	virtual ~Author();

	/** @brief Mostra el nom de l'autor.
	 *  \pre Cert.
	 *  \post El resultat és el nom del paràmetre implícit.
	 */
	string getname() const;

	/** @brief Estableix el nom de l'autor.
	 *  \pre El paràmetre implícit no té nom.
	 *  \post name és el nom del paràmetre implícit.
	 */
	void setname(const string& name);

	/** @brief Mostra el cognom de l'autor.
	 *  \pre Cert.
	 *  \post El resultat és el cognom del paràmatre implícit.
	 */
	string getlastname() const;

	/** @brief Estableix el cognom del paràmetre implícit.
	 * 	\pre El paràmetre implícit no té cognom.
	 * 	\post lastname és el cognom del paràmetre implícit
	 */
	void setlastname(const string& lastname);

	/** @brief Mostra les inicials de l'autor per crear la referència de l'autor.
	 * \pre Cert.
	 * \post Retorna les incials del paràmtre implícit.
	 */
	string getInitials();
};

#endif /* LOGIC_ENTITIES_AUTHOR_H_ */

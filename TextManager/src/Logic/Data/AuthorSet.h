/*
 * AuthorSet.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_AUTHORSET_H_
#define LOGIC_DATA_AUTHORSET_H_

#include "../Entities/Author.h"

class AuthorSet {
private:

public:
	AuthorSet();
	virtual ~AuthorSet();
	//TODO Getters and setters

	/**@brief Afegeix un autor al conjunt
	 * \pre Cert
	 * \post El paràmetre implícit conté l'autor
	 */
	void add(Author a);

	/**@brief Afegeix un autor al conjunt
	 * \pre Cert
	 * \post Si el paràmetre implícit conté l'autor, aquest s'elimina
	 */
	void remove(Author a);

	/**@brief Elimina un autor del conjunt
	 * \pre Cert
	 * \post Si el paràmetre implícit conté un autor amb identificador id, aquest s'elimina
	 */
	void remove(int id);

	/**@brief Retorna l'autor amb l'identificador especificat
	 * \pre L'autor amb identificador id existeix
	 * \post El resultat és la instància de l'autor amb identificador id
	 */
	Author get(int authorID);

	//Print
	/**@brief Escriu la llista d'autors al canal de sortida estàndar
	 * \pre Cert
	 * \post S'ha escrit la llista  d'autors al canal de sortida estàndar
	 */
	void printAuthorList();
};

#endif /* LOGIC_DATA_AUTHORSET_H_ */

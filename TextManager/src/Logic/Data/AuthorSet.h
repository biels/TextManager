/*
 * AuthorSet.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_AUTHORSET_H_
#define LOGIC_DATA_AUTHORSET_H_

#include "../Entities/Author.h"
#include <map>
/**@class AuthorSet
 * @brief Representa un conjunt d'autors.
 */
class AuthorSet {
private:
	int lastID;
	map<int, Author> m;

	/**@brief Calcula l'identificador del següent elememnt del conjunt.
	 * \pre Cert.
	 * \post El resultat és l'identificador que ha de tenir el següent element del conjunt.
	 */
	int getNextID();

public:
	AuthorSet();
	virtual ~AuthorSet();
	//TODO Getters and setters

	/**@brief Afegeix un autor al conjunt
	 * \pre Cert
	 * \post El paràmetre implícit conté l'autor
	 */
	void add(Author a);

	/**
	 * Creates a new element
	 * \post The result is the newly created element
	 */
	Author addNew();

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

	/**@brief Comprova si existeix una cita
	 * \pre Cert
	 * \post El resultat és cert si i nomès si una cita amb identifocador id pertany al conjunt
	 */
	bool exists(int id);

	/**@brief Retorna l'autor amb l'identificador especificat
	 * \pre L'autor amb identificador id existeix
	 * \post El resultat és la instància de l'autor amb identificador id
	 */
	Author get(int id);

	//--Output zone--
	/**@brief Escriu la llista d'autors al canal de sortida estàndar
	 * \pre Cert
	 * \post S'ha escrit la llista  d'autors al canal de sortida estàndar
	 */
	void printAuthorList();
};

#endif /* LOGIC_DATA_AUTHORSET_H_ */

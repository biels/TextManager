/*
 * AuthorSet.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_AUTHORSET_H_
#define LOGIC_DATA_AUTHORSET_H_

#include <map>
#include <string>
#include "../Entities/Text.h"
using namespace std;
class Context;
class Author;
/**@class AuthorSet
 * @brief Representa el conjunt d'autors del sistema.
 */
class AuthorSet {
private:
	int lastID;
	map<int, Author> authors;

	/**@brief Calcula l'identificador del següent elememnt del conjunt.
	 * \pre Cert.
	 * \post El resultat és l'identificador que ha de tenir el següent element del conjunt.
	 */
	int getNextID();
	/**@brief Afegeix un autor al conjunt
	 * \pre Cert
	 * \post El paràmetre implícit conté l'autor
	 */
	void add(const Author& a);

public:
	AuthorSet();
	virtual ~AuthorSet();

	/**@brief Afegeix un autor nou al conjunt
	 * \pre Cert
	 * \post El resultat és el nou autor
	 */
	Author& addNew();

	/**@brief Elimina un autor del conjunt
	 * \pre Cert
	 * \post Si el paràmetre implícit conté un autor amb identificador id, aquest s'elimina
	 */
	void remove(int id);

	/**@brief Elimina un autor del conjunt
	 * \pre Cert
	 * \post Si el paràmetre implícit conté l'autor, aquest s'elimina
	 */
	void remove(const Author& a);

	/**@brief Comprova si existeix una cita
	 * \pre Cert
	 * \post El resultat és cert si i nomès si una cita amb identifocador id pertany al conjunt
	 */
	bool exists(int id);

	/**@brief Retorna l'autor amb l'identificador especificat
	 * \pre L'autor amb identificador id existeix
	 * \post El resultat és la instància de l'autor amb identificador id
	 */
	Author& get(int id);

	/**
	 * @brief Retorna l'id de l'autor
	 * \pre Existeix un autor amb nom "name"
	 * \post El resultat és l'identificador de l'autor "name"
	 * @param name nom i cognom d'un autor
	 */
	int findByFullName(string name);

	/**@brief Escriu la llista d'autors al canal de sortida estàndar
	 * \pre Cert
	 * \post S'ha escrit la llista  d'autors al canal de sortida estàndar
	 */
	void printAuthorList(Context& c);
};

#endif /* LOGIC_DATA_AUTHORSET_H_ */

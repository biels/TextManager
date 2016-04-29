/*
 * TextSet.h
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_TEXTSET_H_
#define LOGIC_DATA_TEXTSET_H_
#include "TextSet.h"
#include "../Entities/Text.h"
#include "../Entities/Quote.h"
#include <string>

using namespace std;

/**@class TextSet
 * @brief Representa un conjunt de textos
 */
class TextSet {
private:
	int nextID;
public:
	TextSet();
	virtual ~TextSet();

	/**@brief Calcula l'identificador del següent elememnt del conjunt
	 * \pre Cert
	 * \post El resultat és l'identificador que ha de tenir el següent element del conjunt
	 */
	int getNextID();

	/**@brief Afegeix un text al conjunt
	 * \pre Cert
	 * \post El paràmetre implícit conté el text t
	 */
	void add(Text t);

	/**@brief Elimina un text amb identificador id
	 * \pre Cert
	 * \post Elimina el text amb identificador id si existeix
	 */
	void remove(int id);

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita q del paràmetre implícit
	 */
	void remove(const Quote& q);

	/**@brief Comprova si l'element amb identificador id pertany al conjunt
	 * \pre Cert
	 * \post El resultat és cert sí i només sí el text amb identificador id existeix
	 */
	bool exists(int id);

	/**@brief Obté un text amb el títol especificat
	 * \pre Existeix un text amb identificador id
	 * \post El resultat és el text amb el títol especificat
	 */
	Text get(int id);
	/**@brief Obté un text amb el títol especificat
	 * \pre Existeix untext amb títol t
	 * \post El resultat és el text amb el títol especificat
	 */
	Text getByTitle(string t);

	/**@brief Obté tots els textos de l'autor amb identificador authorID
	 * \pre Existeix un autor amb el títol authorID
	 * \post El resultat és un conjunt de textos que conté els textos de l'autor id
	 */
	TextSet getAllByAuthor(int id);
};

#endif /* LOGIC_DATA_TEXTSET_H_ */

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

	/**@brief Calcula l'identificador del seg�ent elememnt del conjunt
	 * \pre Cert
	 * \post El resultat �s l'identificador que ha de tenir el seg�ent element del conjunt
	 */
	int getNextID();

	/**@brief Afegeix un text al conjunt
	 * \pre Cert
	 * \post El par�metre impl�cit cont� el text t
	 */
	void add(Text t);

	/**@brief Elimina un text amb identificador id
	 * \pre Cert
	 * \post Elimina el text amb identificador id si existeix
	 */
	void remove(int id);

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita q del par�metre impl�cit
	 */
	void remove(const Quote& q);

	/**@brief Comprova si l'element amb identificador id pertany al conjunt
	 * \pre Cert
	 * \post El resultat �s cert s� i nom�s s� el text amb identificador id existeix
	 */
	bool exists(int id);

	/**@brief Obt� un text amb el t�tol especificat
	 * \pre Existeix un text amb identificador id
	 * \post El resultat �s el text amb el t�tol especificat
	 */
	Text get(int id);
	/**@brief Obt� un text amb el t�tol especificat
	 * \pre Existeix untext amb t�tol t
	 * \post El resultat �s el text amb el t�tol especificat
	 */
	Text getByTitle(string t);

	/**@brief Obt� tots els textos de l'autor amb identificador authorID
	 * \pre Existeix un autor amb el t�tol authorID
	 * \post El resultat �s un conjunt de textos que cont� els textos de l'autor id
	 */
	TextSet getAllByAuthor(int id);
};

#endif /* LOGIC_DATA_TEXTSET_H_ */

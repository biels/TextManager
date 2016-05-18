/*
 * QuoteSet.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_QUOTESET_H_
#define LOGIC_DATA_QUOTESET_H_

#include "../Entities/Quote.h"
#include <map>

using namespace std;

/**@class QuoteSet
 * @brief Representa un conjunt de cites.
 */
class QuoteSet {
private:
	int lastID;
	map<int, Quote> m;

	/**@brief Calcula l'identificador del seg�ent element del conjunt.
	 * \pre Cert.
	 * \post El resultat �s l'identificador que ha de tenir el seg�ent element del conjunt.
	 */
	int getNextID();

	/**@brief Afegeix una cita
	 * \pre Cert
	 * \post S'ha afegit la cita q al par�metre impl�cit
	 */
	void add(const Quote& q);

public:
	QuoteSet();
	virtual ~QuoteSet();

	/**@brief Afegeix un text nou al conjunt
	 * \pre Cert
	 * \post El resultat �s el nou text
	 */
	Quote& addNew();

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita amb identificador id del par�metre impl�cit
	 */
	void remove(int id);

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita q del par�metre impl�cit
	 */
	void remove(const Quote& q);

	/**@brief Comprova si existeix una cita
	 * \pre Cert
	 * \post El resultat és cert si i nom�s si una cita amb identificador id pertany al conjunt
	 */
	bool exists(int id) const;

	/**@brief Consulta la cita amb identificador id
	 * \pre Existeix una cita am identificador id
	 * \post El resultat �s la cita amb identificador id
	 */
	Quote& get(int id);

	/**@brief Consulta totes les cites d'un autor amb identificador id
	 * \pre Existeix un autor amb identificador id
	 * \post El resultat �s un conjunt de cites amb totes les cites de l'autor amb identificador id
	 */
	void printAllByAuthor(int id, Context& c);

	/**@brief Consulta totes les cites que apareixen en un text amb identificador id
	 * \pre Existeix un text amb identificador id
	 * \post El resultat �s un conjunt de cites que cont� totes les cites que apareixen al text amb identificador id
	 */
	void printAllByText(int id);
};

#endif /* LOGIC_DATA_QUOTESET_H_ */

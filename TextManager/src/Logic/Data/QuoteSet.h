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

	/**@brief Calcula l'identificador del següent element del conjunt.
	 * \pre Cert.
	 * \post El resultat és l'identificador que ha de tenir el següent element del conjunt.
	 */
	int getNextID() const;

	/**@brief Afegeix una cita
	 * \pre Cert
	 * \post S'ha afegit la cita q al paràmetre implícit
	 */
	void add(const Quote& q);

public:
	QuoteSet();
	virtual ~QuoteSet();

	/**@brief Afegeix un text nou al conjunt
	 * \pre Cert
	 * \post El resultat és el nou text
	 */
	Quote& addNew();

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita amb identificador id del paràmetre implícit
	 */
	void removeByID(int id);

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita q del paràmetre implícit
	 */
	void removeByQuote(const Quote& q);

	/**@brief Comprova si existeix una cita
	 * \pre Cert
	 * \post El resultat Ã©s cert si i només si una cita amb identificador id pertany al conjunt
	 */
	bool exists(int id) const;

	/**@brief Consulta la cita amb identificador id
	 * \pre Existeix una cita am identificador id
	 * \post El resultat és la cita amb identificador id
	 */
	Quote& get(int id) const;

	/**@brief Consulta totes les cites d'un autor amb identificador id
	 * \pre Existeix un autor amb identificador id
	 * \post El resultat és un conjunt de cites amb totes les cites de l'autor amb identificador id
	 */
	void printAllByAuthor(int id);

	/**@brief Consulta totes les cites que apareixen en un text amb identificador id
	 * \pre Existeix un text amb identificador id
	 * \post El resultat és un conjunt de cites que conté totes les cites que apareixen al text amb identificador id
	 */
	void printAllByText(int id);
};

#endif /* LOGIC_DATA_QUOTESET_H_ */

/*
 * QuoteSet.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_QUOTESET_H_
#define LOGIC_DATA_QUOTESET_H_

#include "../Entities/Quote.h"
using namespace std;

class QuoteSet {
private:

public:
	QuoteSet();
	virtual ~QuoteSet();

	/**@brief Afegeix una cita
	 * \pre Cert
	 * \post S'ha afegit la cita q al par�metre impl�cit
	 */
	void add(Quote q);

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita q del par�metre impl�cit
	 */
	void remove(Quote q);

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita amb identificador id del par�metre impl�cit
	 */
	void remove(int id);

	/**@brief Comprova si existeix una cita
	 * \pre Cert
	 * \post
	 */
	bool exists(int id);

	/**@brief Consulta la cita amb identificador id
	 * \pre Existeix una cita am identificador id
	 * \post El resultat �s la cita amb identificador id
	 */
	Quote getByID(int id);

	/**@brief Consulta totes les cites d'un autor amb identificador id
	 * \pre Existeix un autor amb identificador id
	 * \post El resultat �s un conjunt de cites amb totes les cites de l'autor amb identificador id
	 */
	QuoteSet getAllByAuthor(int id);

	/**@brief Consulta totes les cites que apareixen en un text amb identificador id
	 * \pre Existeix un text amb identificador id
	 * \post El resultat �s un conjunt de cites que cont� totes les cites que apareixen al text amb identificador id
	 */
	QuoteSet getAllByText(int id);
};

#endif /* LOGIC_DATA_QUOTESET_H_ */

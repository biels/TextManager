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

/**@class QuoteSet
 * @brief Representa un conjunt de cites.
 */
class QuoteSet {
private:

public:
	QuoteSet();
	virtual ~QuoteSet();

	/**@brief Afegeix una cita
	 * \pre Cert
	 * \post S'ha afegit la cita q al paràmetre implícit
	 */
	void add(Quote q);

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita q del paràmetre implícit
	 */
	void remove(Quote q);

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita amb identificador id del paràmetre implícit
	 */
	void remove(int id);

	/**@brief Comprova si existeix una cita
	 * \pre Cert
	 * \post El resultat és cert si i nomès si una cita amb identifocador id pertany al conjunt
	 */
	bool exists(int id);

	/**@brief Consulta la cita amb identificador id
	 * \pre Existeix una cita am identificador id
	 * \post El resultat és la cita amb identificador id
	 */
	Quote get(int id);

	/**@brief Consulta totes les cites d'un autor amb identificador id
	 * \pre Existeix un autor amb identificador id
	 * \post El resultat és un conjunt de cites amb totes les cites de l'autor amb identificador id
	 */
	QuoteSet getAllByAuthor(int id);

	/**@brief Consulta totes les cites que apareixen en un text amb identificador id
	 * \pre Existeix un text amb identificador id
	 * \post El resultat és un conjunt de cites que conté totes les cites que apareixen al text amb identificador id
	 */
	QuoteSet getAllByText(int id);
};

#endif /* LOGIC_DATA_QUOTESET_H_ */
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
	void removeByID(int id);

	/**@brief Comprova si existeix una cita
	 * \pre Cert
	 * \post
	 */
	bool exists(Quote q);
	bool existsWithID(int id);
	Quote getByID(int id);
	QuoteSet getAllByID(int id);
	QuoteSet getAll();

};

#endif /* LOGIC_DATA_QUOTESET_H_ */

/*
 * QuoteSet.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_QUOTESET_H_
#define LOGIC_DATA_QUOTESET_H_


#include <map>
class Quote;
class Context;
using namespace std;

/**@class QuoteSet
 * @brief Representa el conjunt de cites.
 */
class QuoteSet {
private:
	int lastID;
	map<int, Quote> quotes;

	map<string, int> lastQuoteNumberMap;

	/**@brief Calcula l'identificador del següent element del conjunt.
	 * \pre Cert.
	 * \post El resultat és l'identificador que ha de tenir el següent element del conjunt.
	 */
	int getNextID();

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

	/**@brief Calcula l'identificador del següent element del conjunt.
	 * \pre Cert.
	 * \post El resultat és l'identificador que ha de tenir el següent element del conjunt.
	 */
	int getNextQuoteNumber(string initials);

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita amb identificador id del paràmetre implícit
	 */
	void remove(int id);

	/**@brief Elimina una cita
	 * \pre Cert
	 * \post Elimina la cita q del paràmetre implícit
	 */
	void remove(const Quote& q);

	/**@brief Comprova si existeix una cita
	 * \pre Cert
	 * \post El resultat és cert si i només si una cita amb identificador id pertany al conjunt
	 */
	bool exists(int id) const;

	bool exists(int startIndex, int endIndex, int textId) const;

	/**@brief Consulta la cita amb identificador id
	 * \pre Existeix una cita amb identificador id
	 * \post El resultat és la cita amb identificador id
	 */
	Quote& get(int id);

	/**
	 * @brief Retorna l'id de la cita amb referència ref
	 * \pre Existeix una cita amb referència red
	 * \post El resultat és l'id de la cita amb referència ref
	 */
	int findByRef(string ref) const;

	/**
	 * @brief Imprimeix totes les cites del sistema
	 * \pre Cert
	 * \post El resultat és totes les cites del sistema
	 * @param c context de la operació
	 */
	void printAll(Context& c) ;

	/**@brief Imprimeix totes les cites d'un autor amb identificador id
	 * \pre Existeix un autor amb identificador id
	 * \post El resultat és un conjunt de cites amb totes les cites de l'autor amb identificador id
	 */
	void printAllByAuthor(int id, Context& c) ;

	/**@brief Consulta totes les cites que apareixen en un text amb identificador id
	 * \pre Existeix un text amb identificador id
	 * \post El resultat és un conjunt de cites que conté totes les cites que apareixen al text amb identificador id
	 */
	void printAllByText(int id, bool associated, Context& c);
};

#endif /* LOGIC_DATA_QUOTESET_H_ */

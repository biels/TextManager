/*
 * TextSet.h
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_TEXTSET_H_
#define LOGIC_DATA_TEXTSET_H_


#include <map>
#include <string>

using namespace std;

class Text;
class Quote;
class Context;

/**@class TextSet
 * @brief Representa el conjunt de textos del sistema.
 */
class TextSet {
private:
	int lastID;
	map<int, Text> texts;

	/**@brief Calcula l'identificador del següent elememnt del conjunt.
	 * \pre Cert.
	 * \post El resultat és l'identificador que ha de tenir el següent element del conjunt.
	 */
	int getNextID();

	/**@brief Afegeix un text al conjunt.
	 * \pre Cert.
	 * \post El paràmetre implícit conté el text t.
	 */
	void add(const Text& t);

public:
	TextSet();
	virtual ~TextSet();

	/**@brief Afegeix un text nou al conjunt
	 * \pre Cert
	 * \post El resultat és el nou text
	 */
	Text& addNew();

	/**@brief Elimina un text amb identificador id.
	 * \pre Cert.
	 * \post Elimina el text amb identificador id si existeix.
	 */
	void remove(int id, Context& c);

	/**@brief Elimina un autor del conjunt
	 * \pre Cert
	 * \post Si el paràmetre implícit conté l'autor, aquest s'elimina
	 */
	void remove(const Text& t, Context& c);

	/**@brief Comprova si l'element amb identificador id pertany al conjunt.
	 * \pre Cert.
	 * \post El resultat és cert sí i només sí el text amb identificador id existeix.
	 */
	bool exists(int id);

	/**@brief Obté un text amb el títol especificat.
	 * \pre Existeix un text amb identificador id.
	 * \post El resultat és el text amb el títol especificat.
	 */
	Text& get(int id);

	/**@brief Obté un text amb el títol especificat.
	 * \pre Existeix untext amb títol t.
	 * \post El resultat és el text amb el títol especificat.
	 */
	int findByTitle(string t) const;

	/** triar per contingut?
	 * @brief Troba si hi ha
	 * \pre
	 * \post
	 * @param list
	 */
	int findByWordList(string list, Context& c);

	/**
	 * @brief Retorna el número de paraules dels textos d'un autor
	 * \pre Cert
	 * \post El resultat és el nombre de paraules que tenen tots els textos del autor amb identificador id
	 * @param id identificador de l'autor
	 */
	int numberWordsAuthorTexts(int id, Context& c) const;

	/**
	 * @brief Retorna el número de frases dels textos d'un autor
	 * \pre Cert
	 * \post El resultat és el nombre de frases que tenen tots els textos del autor amb identificador id
	 * @param id identificador de l'autor
	 * @return
	 */
	int numberSentencesAuthorTexts(int id, Context& c) const;

	/**
	 * @brief Retorna el número de textos d'un autor.
	 * \pre Cert
	 * \post El resultat és el nombre de textos que té l'autor amb identificador id
	 * @param id identificador de l'autor
	 */
	int numberTextsAuthor(int id, Context& c) const;

	/**
	 * @brief Retrona si el text ja existeix, si el resultat es false, es podrà afegir el text al sistema
	 * \pre Cert
	 * \post El resultat és cert si i només sí ja existeix al sistema un text amb mateix títol i autor
	 * @param title títol del text que es vol afegir
	 * @param autor autor del text que es vol afegir
	 */
	bool textAlreadyExists (const string& title, const string& autor, Context& c) const;

	/**
	 * @brief Imprimiex informació del conjunt de textos
	 * \pre	Cert
	 * \post El resultat és el nom i el títol de cada text del sistema
	 */
	void printAll(Context& c);

	/**@brief Obté tots els textos de l'autor amb identificador authorID.
	 * \pre Existeix un autor amb el títol authorID.
	 * \post El resultat és un conjunt de textos que conté els textos de l'autor id.
	 */
	void printAllByAuthor(int id, Context& c);

};

#endif /* LOGIC_DATA_TEXTSET_H_ */

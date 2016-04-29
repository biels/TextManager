/*
 * Text.h
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#ifndef LOGIC_ENTITIES_TEXT_H_
#define LOGIC_ENTITIES_TEXT_H_

#include <string>
#include <vector>
#include "Author.h"
using namespace std;

/** @class Text
 *  @brief Representa un contingut que té un autor i un títol.
 *
 *   Els textos poden correspondre a llibres, articles, manuals, etc.
 */

class Text {
private:
	string title;
	string author;
	vector<string> content;
	vector<pair<int,string>> getFrequencyTable();
	vector<string> getSentenceListByExpression();
	vector<string> getSentenceListByWord();

public:

	/** @brief Creadora per defecte
	 * \pre Cert
	 * \post El resultat es un text sense títol, ni autor, ni contingut.
	 */
	Text();

	virtual ~Text();

	/** @brief Mostra el nom i cognom de l'autor que ha fet el text.
	 * \pre Cert.
	 * \post Retorna el nom i cognom del paràmetre implícit.
	 */
	Author getAuthor() const;

	/** @brief Estableix un autor al text.
	 *	\pre El paràmetre implícit no té autor.
	 *	\post author és el autor del paràmetre implícit.
	 */
	void setAuthor(const Author& author);

	/** @brief Estableix el contingut del text.
	 *  \pre El paràmetre implícit no té contingut.
	 *  \post content és el contingut del paràmetre implícit.
	 */
	void setContent(const vector<string>& content);

	/** @brief Mostra el títol del text.
	 *  \pre Cert.
	 *  \post Retrona el títol del paràmetre implícit.
	 */
	string getTitle() const;

	/** @brief Estableix el títol del text.
	 *  \pre El paràmetre implícit no té títol
	 *  \post title és el títol del paràmetre implícit.
	 */
	void setTitle(const string& title);

	/** @brief Mostra el nombre de frases del contingut del text.
	 *  \pre Cert.
	 *  \post El resultat és el número de frases del text.
	 */
	int getSentenceCount();

	/** @brief Mostra el nombre de paraules del contingut del text.
	 *  \pre Cert.
	 *  \post El resultat és el número de paraules del paràmetre implícit.
	 */
	int getWordCount();

	/** @brief Mostra totes les paraules del text ordenades per freqüència.
	 * \pre Cert.
	 * \post El resultat és totes les paraules del paràmetre implícit ordenades decreixentment per freqüència.
	 * En cas d'empat de freqüència les paraules s'ordenen creixement, primer per llargada i després alfabèticament.
	 */
	void printFrequencyTable();

	/** @brief Mostra les frases del contingut del text triat que compleixen l'expressió.
	 * \pre exp és una expressió booleana de paraules.
	 * \post El resultat són les frases del paràmetre implícit que compleixen exp.
	 */
	void printSentenceListByExpression(string expr);

	/** @brief Mostra les frases on hi apareix la seqüència de paraules en el contingut de l'últim text triat.
	 * \pre word és una seqüència de paraules.
	 * \post El resultat són les frases del paràmetre implícit on apareix word.
	 */
	void printSentenceListByWord(string word);
};

#endif /* LOGIC_ENTITIES_TEXT_H_ */

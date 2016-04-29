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
using namespace std;

/** @class Text
 *  @brief Representa un contingut que té un autor i un títol.
 *
 *   Els textos poden correspondre a llibres, articles,
 *   manuals, etc.
 */

class Text {
private:
	string title;
	string author;
	vector<string> content;

public:

	/** @brief Creadora per defecte
	 * \pre Cert
	 * \post El resultat es un text sense títol, ni autor, ni contingut
	 */
	Text();

	virtual ~Text();

	/** @brief Mostra el nombre de frases del contingut del text.
	 *  \pre Cert
	 *  \post El resultat és el número de frases del text.
	 */
	int getSentenceCount();

	/** @brief Mostra el nombre de paraules del contingut del text.
	 *  \pre Cert
	 *  \post El resultat és el número de paraules del text.
	 */
	int getWordCount();

	/** @brief Mostra totes les paraules del text ordenades per freqüència.
	 * \pre Cert
	 * \post El resultat és totes les paraules del text ordenades decreixentment per freqüència.
	 * En cas d'empat de freqüèencia les paraules s'ordenen creixement, primer per llargada i despréss alfabèticament.
	 */
	FrequencyTable getFrequencyTable();

	/** @brief Mostra les frases del contingut del text triat que compleixen l'expressió.
	 * \pre exp és una expressió booleana de paraules.
	 * \post El resultat són les frases del text que compleixen exp.
	 */
	SentenceList getSentenceListByExpression(Expression exp);

	/** @brief Mostra les frases on hi apareix la seqüència de paraules en el contingut de l'últim text triat.
	 * \pre "word" és una seqüència de paraules
	 * \post El resultat són les frases del text on apareix word.
	 */
	SentenceList getSentenceListByWord((Struct) word);
};

#endif /* LOGIC_ENTITIES_TEXT_H_ */

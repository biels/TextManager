/*
 * Text.h
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#ifndef LOGIC_ENTITIES_TEXT_H_
#define LOGIC_ENTITIES_TEXT_H_

class Context;
#include <string>
#include <vector>
#include <map>
class Author;
class Quote;
using namespace std;


/** @class Text
 *  @brief Representa un contingut que tÃ© un autor i un tÃ­tol.
 *  Els textos poden correspondre a llibres, articles, manuals, etc.
 */

class Text {
private:
	int id;
	int wordCount; //Since [.] are stored in vector elements, .size() would be inaccurate
	int author;
	string title; //Won't degrade performance since no room for scaling
	vector<string> content; // punctuation signs saved in their own elements
	vector<int> sentences;			//index: nº frase, 2n int nº paraula
	vector<pair<string, int>> frequencyTable;

public:
	/** @brief Creadora per defecte
	 * \pre Cert
	 * \post El resultat es un text sense tÃ­tol, ni autor, ni contingut.
	 */
	Text(int id);

	/**
	 * @brief Destructora per defecte
	 */
	virtual ~Text();

	/**@brief Mostra l'identificador del text
	 * \pre Cert.
	 * \post El resultat és l'identificador del paràmetre implícit.
	 */
	int getId() const;

	/** @brief Mostra el títol del text.
	 *  \pre Cert.
	 *  \post Retrona el títol del paràmetre implícit.
	 */
	string getTitle() const;

	/** @brief Estableix el títol del text.
	 *  \pre El paràmetre implícit no té títol
	 *  \post title és el títol del paràmetre implícit.
	 */
	void setTitle(const string title);

	/** @brief Mostra el nom i cognom de l'autor que ha fet el text.
	 * Read only, @see AuthorSet.get() to modify
	 * \pre Cert.
	 * \post Retorna el nom i cognom del paràmetre implícit.
	 */
	Author& getAuthor(Context& c);

	/** @brief Estableix un autor al text.
	 *	\pre El paràmetre implícit no té autor.
	 *	\post author és el autor del paràmetre implícit.
	 */
	void setAuthor(const Author& author);

	/**
	 * @brief Estableix el nom de l'autor
	 * \pre El text no té nom d'autor, o si en té, és diferent a fullName
	 * \post El resultat és el text amb author igual a fullName
	 * @param fullName nom de l'autor del text
	 */
	void setAuthorByFullName(string fullName, Context& c);

	/** @brief Estableix el contingut del text.
	 *  \pre El paràmetre implícit no té contingut.
	 *  \post content és el contingut del paràmetre implícit.
	 */
	void setContent(string content);

	/** @brief Mostra el nombre de frases del contingut del text.
	 *  \pre Cert.
	 *  \post El resultat és el número de frases del text.
	 */
	int getSentenceCount() const;

	/** @brief Mostra el nombre de paraules del contingut del text.
	 *  \pre Cert.
	 *  \post El resultat és el número de paraules del paràmetre implícit.
	 */
	int getWordCount() const;

	/**
	 * @brief Retorna una frase
	 * \pre Cert
	 * \post El resultat és la frase del text que comença en la posició index
	 * @param index indica la posició on comença la frase
	 */
	string getSentenceByIndex(int index) const;

	/**
	 * @brief Substitueix una paraula per una altra en el text
	 * \pre Hi ha un text triat
	 * \post El resultat és el text triat canviat, on abans hi havia la paraula match, ara hi és replace
	 * @param match paraula que serà susbstituida
	 * @param replace paraula per la que es substitueix
	 */
	void replace(string match, string replace);

	/**
	 * @brief Retorna una cita
	 * \pre Hi ha un text triat
	 * \post El resultat és la cita que comença en la posició from i acaba en la posició to del text.
	 * @param from posició del text on comença la cita
	 * @param to posició del text on acaba la cita
	 */
	Quote& extractQuote(int from, int to, Context& c);

	/**
	 * @brief
	 * @param match
	 * @param ls
	 */
	void getSentencesMatchingWordList(vector<int>& match, string ls) const;

	/**
	 *
	 * @param list
	 * @param c
	 * @return
	 */
	bool matchesWordListAnywhere(string list, Context& c);

	/**
	 * @brief Retorna una llista
	 * @param expr
	 * @param match
	 */
	void getSentenceListMatchingExpression(string expr, vector<int>& match) const;

	/**
	 *
	 * @param expr
	 * @param match
	 * @param cond
	 * @param c_op
	 * @param root
	 */
	void getSentenceListMatchingExpressionEf(string expr, vector<int>& match, vector<string>& cond, bool& c_op, bool root) const;

	/**
	 *
	 * @param match
	 * @param cond
	 * @param c_op
	 * @param m_op
	 */
	void getSentenceListMatchingWordListInContext(vector<int>& match, vector<string>& cond, bool c_op, bool m_op) const;

	/**
	 *
	 * @param i
	 * @param c_op
	 * @param remaining
	 */
	void checkSentenceForCondition(int i, bool c_op, vector<string>& remaining) const;


	/**
	 * @brief Calcula la taula de freqüències
	 * \pre No existeix cap taula de freqüències del text.
	 * \post El resultat és la taula de freqüències del contingut del text.
	 */
	void calculateFrequencyTable();

	/**
	 * @brief Actualitza la taula de freqüències
	 * \pre La taula de freqüencies pot estar desordenada després d'haver cridat la funció @see replace(string match, string replace)
	 * @param match paraula que disminueix de freqüencia al haver estat reemplaçada
	 * @param replace paraula nova o existent que augmenta freqüència
	 */
	void updateFrequencyTable(string match, string replace);

	/**
	 * @brief Ordena la taula de freqüències
	 * \pre La taula de freqüències pot no estar ordenada adecuadament
	 * \post La taula de freqüències està ordenada per freqüència de les paraules, si hi ha empat s'ordenen creixement, primer per llargada i després alfabèticament.
	 */
	void sortFrequencyTable();

	/** @brief Mostra les frases del contingut del text triat que compleixen l'expressió.
	 * \pre exp és una expressió booleana de paraules.
	 * \post El resultat són les frases del paràmetre implícit que compleixen exp.
	 */

	//Output section

	/** @brief Mostra totes les paraules del text ordenades per freqüència.
	 * \pre Cert.
	 * \post El resultat és totes les paraules del paràmetre implícit ordenades decreixentment per freqüència.
	 *
	 */
	void printFrequencyTable();

	/**
	 * @brief Imprimieix frases del text.
	 * \pre
	 * \post
	 * @param expr
	 */
	void printSentenceListMatchingExpression(string expr) const;

	/** @brief Mostra les frases on hi apareix la seqüència de paraules en el contingut de l'últim text triat.
	 * \pre Cert
	 * \post El resultat són les frases del paràmetre implícit on apareix word.
	 * @param sequence seqüència de paraules que s'ha de cumplir
	 */
	void printSentenceListContainingSequence(string sequence) const;

	/**
	 * @brief Imprimeix el nom de l'autor i el títol
	 * \pre Hi ha un text triat
	 * \post El resultat és el nom i cognom de l'autor i el títol del text del text triat
	 */
	void printHeader(Context& c);

	/**
	 * @brief Imprimeix informació del text
	 * \pre Hi ha un text triat
	 * \post El resultat són el nombre de frases, el nombre de paraules i les cites associades al text, si info és cert, del text triat
	 * @param info si és cert, imprimeix les cites associades al text
	 */
	void printInfo(Context& c, bool info); //TODO IMPLEMENT

	/**
	 * @brief Imprimeix el contingut del text
	 * \pre Hi ha un text triat
	 * \post El resultat són les frases del text triat
	 */
	void printContent(); //TODO Consultar

	/**
	 * @brief
	 * \pre
	 * \post
	 * @param from
	 * @param to
	 */
	void printSentenceListInRange(int from, int to);
};

#endif /* LOGIC_ENTITIES_TEXT_H_ */

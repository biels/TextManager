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
	string title; //Won't degrade performance since no room for scaling
	int author;
	vector<string> content; // punctuation signs saved in their own elements
	int wordCount; //Since [.] are stored in vector elements, .size() would be inaccurate
	vector<int> sentences;			//index: nº frase, 2n int nº paraula
	vector<string> getSentenceListByExpression();
	vector<string> getSentenceListByWord();
	vector<pair<string, int>> frequencyTable;

public:
	/** @brief Creadora per defecte
	 * \pre Cert
	 * \post El resultat es un text sense tÃ­tol, ni autor, ni contingut.
	 */
	Text(int id);

	virtual ~Text();

	/**@brief Mostra l'identificador del text
	 * \pre Cert.
	 * \post El resultat Ã©s l'identificador del parÃ metre implÃ­cit.
	 */
	int getId() const;

	/** @brief Mostra el tÃ­tol del text.
	 *  \pre Cert.
	 *  \post Retrona el tÃ­tol del parÃ metre implÃ­cit.
	 */
	string getTitle() const;

	/** @brief Estableix el tÃ­tol del text.
	 *  \pre El parÃ metre implÃ­cit no tÃ© tÃ­tol
	 *  \post title Ã©s el tÃ­tol del parÃ metre implÃ­cit.
	 */
	void setTitle(const string& title);

	/** @brief Mostra el nom i cognom de l'autor que ha fet el text.
	 * Read only, @see AuthorSet.get() to modify
	 * \pre Cert.
	 * \post Retorna el nom i cognom del parÃ metre implÃ­cit.
	 */
	Author& getAuthor(Context& c);

	/** @brief Estableix un autor al text.
	 *	\pre El parÃ metre implÃ­cit no tÃ© autor.
	 *	\post author Ã©s el autor del parÃ metre implÃ­cit.
	 */
	void setAuthor(const Author& author);

	void setAuthorByFullName(string fullName, Context& c);

	/** @brief Estableix el contingut del text.
	 *  \pre El parÃ metre implÃ­cit no tÃ© contingut.
	 *  \post content Ã©s el contingut del parÃ metre implÃ­cit.
	 */
	void setContent(const string& content);

	/** @brief Mostra el nombre de frases del contingut del text.
	 *  \pre Cert.
	 *  \post El resultat Ã©s el nÃºmero de frases del text.
	 */
	int getSentenceCount() const;

	/** @brief Mostra el nombre de paraules del contingut del text.
	 *  \pre Cert.
	 *  \post El resultat Ã©s el nÃºmero de paraules del parÃ metre implÃ­cit.
	 */
	int getWordCount() const;

	string getSentenceByIndex(int index) const;

	void replace(string match, string replace);

	Quote& extractQuote(int from, int to, Context& c);

	bool matchesWordListAnywhere(string list, Context& c);

	void getSentenceListMatchingExpression(string expr, vector<int>& match) const;

	void getSentenceListMatchingExpressionEf(string expr, vector<int>& match, vector<string>& cond, bool& c_op, bool root) const;

	void getSentenceListMatchingWordListInContext(vector<int>& match, vector<string>& cond, bool c_op, bool m_op) const;

	void checkSentenceForCondition(int i, bool c_op,
				vector<string>& remaining) const;
	//Output section

	/** @brief Mostra totes les paraules del text ordenades per freqÃ¼Ã¨ncia.
	 * \pre Cert.
	 * \post El resultat Ã©s totes les paraules del parÃ metre implÃ­cit ordenades decreixentment per freqÃ¼Ã¨ncia.
	 * En cas d'empat de freqÃ¼Ã¨ncia les paraules s'ordenen creixement, primer per llargada i desprÃ©s alfabÃ¨ticament.
	 */
	void printFrequencyTable();

	void calculateFrequencyTable();

	void sortFrequencyTable();

	void updateFrequencyTable(string match, string replace);

	/** @brief Mostra les frases del contingut del text triat que compleixen l'expressiÃ³.
	 * \pre exp Ã©s una expressiÃ³ booleana de paraules.
	 * \post El resultat sÃ³n les frases del parÃ metre implÃ­cit que compleixen exp.
	 */
	void printSentenceListMatchingExpression(string expr) const;

	/** @brief Mostra les frases on hi apareix la seqÃ¼Ã¨ncia de paraules en el contingut de l'Ãºltim text triat.
	 * \pre word Ã©s una seqÃ¼Ã¨ncia de paraules.
	 * \post El resultat sÃ³n les frases del parÃ metre implÃ­cit on apareix word.
	 */
	void printSentenceListContainingSequence(string sequence) const;

	void printInfo(Context& c, bool info); //TODO IMPLEMENT

	void printContent(); //TODO Consultar
	void printSentenceListInRange(int from, int to);
};

#endif /* LOGIC_ENTITIES_TEXT_H_ */

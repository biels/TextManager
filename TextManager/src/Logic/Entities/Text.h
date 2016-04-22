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

class Text {
private:
	string title;
	string author;
	vector<string> content;

public:
	// Constructora
	Text();
	/* Pre: cert */
	/* Post: el resultat es un text sense títol, ni autor, ni contingut */

	// Destructora
	virtual ~Text();

	// Modificadores
	void setAuthor(string author);
	/* Pre: El parametre implícit no té autor*/
	/* Post: L'autor del parametre implícit passa a ser "autor" */
	void setTitle(string title);
	/* Pre: El parametre implícit no té títol*/
	/* Post: El títol del parametre implícit passa a ser "title" */

	// Consultores
	string getAuthor() const;
	/* Pre: cert */
	/* Post: el resultat es l'autor del text */

	string getTitle() const;
	/* Pre: cert */
	/* Post: el resultat es el títol del text */

};

#endif /* LOGIC_ENTITIES_TEXT_H_ */

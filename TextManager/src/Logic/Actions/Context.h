/*
 * Context.h
 *
 *  Created on: 15 maig 2016
 *      Author: Biel
 */

#ifndef LOGIC_ACTIONS_CONTEXT_H_
#define LOGIC_ACTIONS_CONTEXT_H_

#include "../Data/TextSet.h"
#include "../Data/AuthorSet.h"
#include "../Data/QuoteSet.h"
class Text;

/**@class Context
 * @brief
 */

class Context {
private:
	TextSet ts;
	AuthorSet as;
	QuoteSet qs;
	int chosenTextID;

public:
	/**
	 * @brief Creadora per defecte
	 * \pre Cert
	 * \post Crea un Context sense conjunt de textos, ni conjunt d'autors, ni conjunt de cites, i amb identificador de text igual a -1
	 */
	Context();

	/**
	 * @brief Destructora per defecte
	 */
	virtual ~Context();

	/**
	 * @brief Retorna un conjunt d'autors
	 * \pre Cert
	 * \post El resultat és el conjunt d'autors del sistema
	 */
	AuthorSet& getAs();

	/**
	 * @brief Retorna un conjunt de cites
	 * \pre Cert
	 * \post El resultat és el conjunt de cites del sistema
	 */
	QuoteSet& getQs();

	/**
	 * @brief Retorna un conjunt de textos
	 * \pre Cert
	 * \post El resultat és el conjunt de textos del sistema
	 */
	TextSet& getTs();

	/**
	 * @brief Retorna l'id d'un text
	 * \pre Hi ha un text triar
	 * \post El resultat és l'identificador del text triat
	 */
	int getChosenTextId() const;

	/**
	 * @brief Retorna si existeix un text triat
 	 * \pre Cert
	 * \post El resultat és true si hi ha un text triat, i false en qualsevol altre cas
	 * @return
	 */
	bool existsChosenText() const;

	/**
	 * @brief Estableix un id al text triat
	 * \pre Hi ha un text triat
	 * \post El text triat ja té el seu identificador establert
	 * @param chosenTextId identificador del text
	 */
	void setChosenTextId(int chosenTextId);

	/**
	 * @brief Retorna un text
	 * \pre Hi ha un text triat
	 * \post El resultat és el text triat
	 */
	Text& getChosenText();
};

#endif /* LOGIC_ACTIONS_CONTEXT_H_ */

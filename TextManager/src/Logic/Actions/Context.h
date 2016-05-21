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
class Context {
private:
	TextSet ts;
	AuthorSet as;
	QuoteSet qs;
	int chosenTextID;
public:
	Context();
	virtual ~Context();
	AuthorSet& getAs();
	QuoteSet& getQs();
	TextSet& getTs();
	int getChosenTextId() const;
	bool existsChosenText() const;
	void setChosenTextId(int chosenTextId);
	Text& getChosenText();
};

#endif /* LOGIC_ACTIONS_CONTEXT_H_ */

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
class Context {
	TextSet ts;
	AuthorSet as;
	QuoteSet qs;
	int chosenTextID;
public:
	Context();
	virtual ~Context();
	const AuthorSet& getAs() const;
	const QuoteSet& getQs() const;
	const TextSet& getTs() const;
	int getChosenTextId() const;
	void setChosenTextId(int chosenTextId);
};

#endif /* LOGIC_ACTIONS_CONTEXT_H_ */

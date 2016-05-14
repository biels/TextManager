/*
 * Context.h
 *
 *  Created on: 15 maig 2016
 *      Author: Biel
 */

#ifndef LOGIC_ACTIONS_CONTEXT_H_
#define LOGIC_ACTIONS_CONTEXT_H_

class Context {
private:
	TextSet ts;
	AuthorSet as;
	QuoteSet qs;
	int chosenTextID;
public:
	Context();
	virtual ~Context();
};

#endif /* LOGIC_ACTIONS_CONTEXT_H_ */

/*
 * ActionHandler.h
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#ifndef LOGIC_ACTIONS_ACTIONHANDLER_H_
#define LOGIC_ACTIONS_ACTIONHANDLER_H_

class ActionHandler {
private:
	TextSet s;
public:
	ActionHandler(TextSet data);
	virtual ~ActionHandler();
};

#endif /* LOGIC_ACTIONS_ACTIONHANDLER_H_ */

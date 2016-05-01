/*
 * ConditionalExpression.h
 *
 *  Created on: 2 maig 2016
 *      Author: Biel
 */

#ifndef LOGIC_ACTIONS_DATASTRUCTURES_CONDITIONALEXPRESSION_H_
#define LOGIC_ACTIONS_DATASTRUCTURES_CONDITIONALEXPRESSION_H_
#include <string>
#include <vector>

using namespace std;

struct ConditionalExpression{
	vector<ConditionalExpression> childs;
	int op; //[0 -> AND, 1 -> OR]
	vector<string> arr;
	bool isArr;

};
inline ConditionalExpression operator&&(const ConditionalExpression& x, const ConditionalExpression& y){
	ConditionalExpression c;
	c.childs.push_back(x);
	c.childs.push_back(y);
	c.op = 0;
	return c;
}
inline ConditionalExpression operator||(const ConditionalExpression& x, const ConditionalExpression& y){
	ConditionalExpression c;
	c.childs.push_back(x);
	c.childs.push_back(y);
	c.op = 1;
	return c;
}

#endif /* LOGIC_ACTIONS_DATASTRUCTURES_CONDITIONALEXPRESSION_H_ */

/*
 * Context.cpp
 *
 *  Created on: 15 maig 2016
 *      Author: Biel
 */

#include "Context.h"

Context::Context() {
	chosenTextID = -1;

}

AuthorSet& Context::getAs() {
	return as;
}

QuoteSet& Context::getQs() {
	return qs;
}


TextSet& Context::getTs() {
	return ts;
}

int Context::getChosenTextId() const {
	return chosenTextID;
}

void Context::setChosenTextId(int chosenTextId) {
	chosenTextID = chosenTextId;
}

Context::~Context() {
	// TODO Auto-generated destructor stub
}


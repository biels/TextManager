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

const AuthorSet& Context::getAs() const {
	return as;
}

const QuoteSet& Context::getQs() const {
	return qs;
}

int Context::getChosenTextId() const {
	return chosenTextID;
}

void Context::setChosenTextId(int chosenTextId) {
	chosenTextID = chosenTextId;
}

const TextSet& Context::getTs() const {
	return ts;
}

Context::~Context() {
	// TODO Auto-generated destructor stub
}


/*
 * Context.cpp
 *
 *  Created on: 15 maig 2016
 *      Author: Biel
 */

#include "Context.h"
#include "../Entities/Text.h"


Context::Context() {
	chosenTextID = -1;
}

Context::~Context() {
	// TODO Auto-generated destructor stub
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
	if(chosenTextId == -1)return;
	getChosenText().calculateFrequencyTable();
	getChosenText().sortFrequencyTable();
}

bool Context::existsChosenText() const{
	return chosenTextID >= 0;
}

Text& Context::getChosenText(){
	return getTs().get(getChosenTextId());
}

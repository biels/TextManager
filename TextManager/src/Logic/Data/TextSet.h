/*
 * TextSet.h
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_TEXTSET_H_
#define LOGIC_DATA_TEXTSET_H_
#include "TextSet.h"
#include "../Entities/Text.h"
#include <string>
using namespace std;


class TextSet {
private:

public:
	TextSet();
	virtual ~TextSet();
	Text getTextByTitle(string title);
	TextSet getTextsByAuthor(string author);
};

#endif /* LOGIC_DATA_TEXTSET_H_ */

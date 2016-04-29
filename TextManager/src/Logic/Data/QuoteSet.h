/*
 * QuoteSet.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_QUOTESET_H_
#define LOGIC_DATA_QUOTESET_H_

class QuoteSet {
private:

public:
	QuoteSet();
	virtual ~QuoteSet();

	void add(Quote q);
	void remove(Quote q);
	void remove(int id);
	bool exists(Quote q);
	bool exists(int id);
	Quote getByID(int id);
	QuoteSet getAllByID(int id);
	QuoteSet getAll();

};

#endif /* LOGIC_DATA_QUOTESET_H_ */

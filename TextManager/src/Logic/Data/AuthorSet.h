/*
 * AuthorSet.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Biel
 */

#ifndef LOGIC_DATA_AUTHORSET_H_
#define LOGIC_DATA_AUTHORSET_H_
class AuthorSet {
public:
	AuthorSet();
	virtual ~AuthorSet();
	//TODO Getters and setters
	void add(Author a);
	void remove(Author a);
	void remove(int id);
	Author getByID(int authorID);

};

#endif /* LOGIC_DATA_AUTHORSET_H_ */

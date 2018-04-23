/*
 * Cat.h
 *
 *  Created on: Apr 20, 2018
 *      Author: Cherie
 */

#ifndef CAT_H_
#define CAT_H_

class Cat {
private:
	bool happy;
	int lives;

public:
	Cat();
	~Cat();
	void speak();
	void status();
};

#endif /* CAT_H_ */

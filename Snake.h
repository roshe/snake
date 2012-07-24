/*
 * Snake.h
 *
 *  Created on: Jul 24, 2012
 *      Author: rob
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include <ncurses.h>
#include <cstdlib>
#include <string>

namespace std {

class Snake {

private:
	int xpos;
	int ypos;

	int xdir;
	int ydir;

	int length;

	string printstring;

public:
	Snake(int inxpos, int inypos, int inxdir, int inydir, int inlength, string inprintstring);
	virtual ~Snake();

	void Iterate();
	void Draw();
};

} /* namespace Snake */
#endif /* SNAKE_H_ */

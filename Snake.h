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
#include <vector>

namespace std {

struct snakesector
{
	int xpos;
	int ypos;
	char printchar;
};

class Snake {

private:
	int xdir;				//X direction. 1 = Right, -1 = Left
	int ydir;				//Y direction. 1 = Down, -1 = Up

	int length;				//Length of the snake in characters

	string printstring;		//The string to represent the snake.
							//Prints one character from the string
							//for each character of the snake's length.
							//A string shorter than the snake's length will loop.

	vector<snakesector> sectors;
	
public:

	Snake(int inxpos, int inypos, int inxdir, int inydir, string inprintstring);
	virtual ~Snake();

	void Iterate();
	void Draw();
};

} /* namespace Snake */
#endif /* SNAKE_H_ */

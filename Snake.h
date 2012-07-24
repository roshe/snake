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
#include <snakesector.h>

namespace std {

class Snake {

private:
	int xpos;				//X position of the snake's head
	int ypos;				//Y position of the snake's head

	int xdir;				//X direction. 1 = Right, -1 = Left
	int ydir;				//Y direction. 1 = Down, -1 = Up

	int length;				//Length of the snake in characters

	string printstring;		//The string to represent the snake.
							//Prints one character from the string
							//for each character of the snake's length.
							//A string shorter than the snake's length will loop.

	vector<snakesector> sectors;

public:
	Snake(int inxpos, int inypos, int inxdir, int inydir, int inlength, string inprintstring);
	virtual ~Snake();

	void Iterate();
	void Draw();
};

} /* namespace Snake */
#endif /* SNAKE_H_ */

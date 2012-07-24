/*
 * Snake.cpp
 *
 *  Created on: Jul 24, 2012
 *      Author: rob
 */

#include "Snake.h"

namespace std{

Snake::Snake(int inxpos, int inypos, int inxdir, int inydir, int inlength, string inprintstring)
{
	xpos = inxpos;
	ypos = inypos;
	xdir = inxdir;
	ydir = inydir;
	length = inlength;
	printstring = inprintstring;


}

Snake::~Snake() {
	// TODO Auto-generated destructor stub
}

void Snake::Draw() //Draws the snake, starting from the head.
{
	int i = 0;
	int xpostemp = xpos;
	int ypostemp = ypos;

	int xdirtemp = xdir;
	int ydirtemp = ydir;

	int maxx;
	int maxy;
	int minx;
	int miny;

	int stringlength = printstring.length() - 1; //Get length of string, ignoring \n
	int stringindex = -1;

	getmaxyx(stdscr, maxy, maxx); //Store maximum x and y coordinates of the window
	getbegyx(stdscr, miny, minx); //Store minimum x and y coordinates of the window

	maxy = maxy - 1;
	maxx = maxx - 1;

	for(i = 0; i < length; i++)
	{
		//Invert x direction if the snake has hit the
		//side of the window

		if(xpostemp == maxx || xpostemp == minx)
		{
			xdirtemp = 0 - xdirtemp;
		}

		//Invert y direction if the snake has hit the
		//top or bottom of the window.
		if(ypostemp == maxy || ypostemp == miny)
		{
			ydirtemp = 0 - ydirtemp;
		}

		//Prepare coordinates for the next section of the snake.
		xpostemp -= xdirtemp;
		ypostemp -= ydirtemp;

		//Move to next character in the snake's string
		stringindex++;

		//If the end of the string has been reached, reset index.
		if(stringindex > stringlength)
		{
			stringindex = 0;
		}

		//Move to the next section and write character.
		move(ypostemp,xpostemp);
		printw("%c", printstring[stringindex]);
	}
}

void Snake::Iterate()
{
	int maxx;
	int maxy;
	int minx;
	int miny;

	//Get min and max coordinates for the screen.
	getmaxyx(stdscr, maxy, maxx);
	getbegyx(stdscr, miny, minx);

	maxx = maxx - 1;
	maxy = maxy - 1;

	//Move the head of the snake in the direction it is travelling.
	xpos += xdir;
	ypos += ydir;

	//If the snake has reached the edge of the screen,
	//invert its direction away from it.
	if(xpos >= maxx || xpos <= minx)
	{
		xdir = 0 - xdir;
	}

	if(ypos >= maxy || ypos <= miny)
	{
		ydir = 0 - ydir;
	}

}


} /* namespace Snake */

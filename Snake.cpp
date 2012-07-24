/*
 * Snake.cpp
 *
 *  Created on: Jul 24, 2012
 *      Author: rob
 */

#include "Snake.h"

namespace std{

Snake::Snake(int inxpos, int inypos, int inxdir, int inydir, int inlength, string inprintstring) {
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

void Snake::Draw()
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

	getmaxyx(stdscr, maxy, maxx);
	getbegyx(stdscr, miny, minx);

	maxy = maxy - 1;
	maxx = maxx - 1;

	for(i = 0; i < length; i++)
	{
		if(xpostemp == maxx || xpostemp == minx)
		{
			xdirtemp = 0 - xdirtemp;
		}

		if(ypostemp == maxy || ypostemp == miny)
		{
			ydirtemp = 0 - ydirtemp;
		}

		xdirtemp = (xdirtemp > 0) ? 1 : -1;
		ydirtemp = (ydirtemp > 0) ? 1 : -1;

		xpostemp -= xdirtemp;
		ypostemp -= ydirtemp;

		stringindex++;

		if(stringindex > stringlength)
		{
			stringindex = 0;
		}

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

	getmaxyx(stdscr, maxy, maxx);
	getbegyx(stdscr, miny, minx);

	maxx = maxx - 1;
	maxy = maxy - 1;

	xpos += xdir;
	ypos += ydir;

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

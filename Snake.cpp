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
	int i = 0;

	int maxx;
	int maxy;
	int minx;
	int miny;

	int xdirtemp;
	int ydirtemp;

	xdir = inxdir;
	ydir = inydir;
	length = inlength;
	printstring = inprintstring;

	sectors.resize(length);

	sectors[0].xpos = inxpos;
	sectors[0].ypos = inypos;

	xdirtemp = xdir;
	ydirtemp = ydir;

	for(i = 0; i < length; i++)
	{
		sectors[i].printchar = '#';//printstring[i];
	}


	i = 1;

	//Get min and max coordinates for the screen.
	getmaxyx(stdscr, maxy, maxx);
	getbegyx(stdscr, miny, minx);

	maxx = maxx - 1;
	maxy = maxy - 1;

	for(i = 1; i < length; i++)
	{
		sectors[i].xpos = sectors[0].xpos - (xdirtemp * i);
		sectors[i].ypos = sectors[0].ypos - (ydirtemp * i);

		if (sectors[i].xpos >= maxx || sectors[i].xpos <= minx)
		{
			xdirtemp = 0 - xdirtemp;
		}
		if (sectors[i].ypos >= maxy || sectors[i].ypos <= miny)
		{
			ydirtemp = 0 - ydirtemp;
		}
	}

	refresh();
}

Snake::~Snake() {
	// TODO Auto-generated destructor stub
}

void Snake::Draw() //Draws the snake, starting from the head.
{
	int i = 0;

	for(i = 0; i < length; i++)
	{
		move(sectors[i].ypos, sectors[i].xpos);
		printw("%c", sectors[i].printchar);
	}

	move(30,30);

	for(i = 0; i < length; i++)
	{
		printw("%d:%d, ", sectors[i].xpos, sectors[i].ypos);
	}
}

void Snake::Iterate() //Fills the sectors vector with the coordinates of the snake
{
	int maxx;
	int maxy;
	int minx;
	int miny;

	int i = length;

	//Get min and max coordinates for the screen.
	getmaxyx(stdscr, maxy, maxx);
	getbegyx(stdscr, miny, minx);

	maxx = maxx - 1;
	maxy = maxy - 1;

	for(i = length; i > 2; i--)
	{
		sectors[i].xpos = sectors[i - 1].xpos;
		sectors[i].ypos = sectors[i - 1].ypos;
	}

	sectors[0].xpos += xdir;
	sectors[0].ypos += ydir;

	if(sectors[0].xpos >= maxx || sectors[0].xpos <= minx)
	{
		xdir = 0 - xdir;
	}

	if(sectors[0].ypos >= maxy || sectors[0].ypos <= miny)
	{
		ydir = 0 - ydir;
	}
}


} /* namespace Snake */

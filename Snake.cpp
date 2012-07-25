/*
 * Snake.cpp
 *
 *  Created on: Jul 24, 2012
 *      Author: rob
 */

#include "Snake.h"

namespace std{

Snake::Snake(int inxpos, int inypos, int inxdir, int inydir, string inprintstring)
{
	int i = 0;

	xdir = inxdir;
	ydir = inydir;
	printstring = inprintstring;
	length = printstring.length();

	sectors.resize(length);

	sectors[0].xpos = inxpos;
	sectors[0].ypos = inypos;

	for(i = 0; i < length; i++)
	{
		sectors[i].printchar = printstring[i];
	}


	i = 1;

	for(i = 1; i < length; i++)
	{
		sectors[i].xpos = sectors[0].xpos - (xdir * i);
		sectors[i].ypos = sectors[0].ypos - (ydir * i);
	}

	refresh();
}

Snake::~Snake() {
	// TODO Auto-generated destructor stub
}

void Snake::Draw() //Draws the snake, starting from the head.
{
	int i = 0;
	
	int maxx, maxy, minx, miny;

	getmaxyx(stdscr, maxy, maxx);
	getbegyx(stdscr, miny, minx);

	for(i = 0; i < length; i++)
	{
		if((miny <= sectors[i].ypos) && (sectors[i].ypos < maxy) && (minx <= sectors[i].xpos) && (sectors[i].xpos < maxx))
		{
			move(sectors[i].ypos, sectors[i].xpos);
			printw("%c", sectors[i].printchar);
		}
	}
}

void Snake::Iterate() //Fills the sectors vector with the coordinates of the snake
{
	int maxx;
	int maxy;
	int minx;
	int miny;

	int i = length;

	vector<snakesector> sectorstemp;

	sectorstemp.resize(length);

	//Get min and max coordinates for the screen.
	getmaxyx(stdscr, maxy, maxx);
	getbegyx(stdscr, miny, minx);

	maxx = maxx - 1;
	maxy = maxy - 1;

	sectorstemp[0].xpos = sectors[0].xpos;
	sectorstemp[0].ypos = sectors[0].ypos;

	for(i = 1; i < length; i++)
	{
		sectorstemp[i].xpos = sectors[i-1].xpos;
		sectorstemp[i].ypos = sectors[i-1].ypos;
	}

	sectorstemp[0].xpos += xdir;
	sectorstemp[0].ypos += ydir;

	for(i = 0; i < length; i++)
	{
		sectors[i].xpos = sectorstemp[i].xpos;
		sectors[i].ypos = sectorstemp[i].ypos;
	}

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

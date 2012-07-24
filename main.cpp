#include <iostream>
#include <unistd.h>
#include "Snake.h"

using namespace std;

int main()
{
	int delay = 100000; //Microsecond delay, 1,000,000 in one second

	Snake snakeone(12, 12, 1, 1, 15, "1**************");
	Snake snaketwo(40, 10, -1, 1, 10, "2*********");
	Snake snakethree(50, 40, -1, -1, 20, "3*******************");
	Snake snakefour (20, 0, 1, 1, 12, "4**********#");

	initscr(); 		//Start ncurses
	noecho();  		//Don't print keyboard input
	curs_set(0);	//Don't show cursor
	timeout(0);		//Make getch non-blocking

	while(1)
	{
		clear();
		snakeone.Draw();
		snakeone.Iterate();

		snaketwo.Draw();
		snaketwo.Iterate();

		snakethree.Draw();
		snakethree.Iterate();

		snakefour.Draw();
		snakefour.Iterate();

		refresh();

		usleep(delay);

		if (getch() == 'q')
		{
			break;
		}
	}

	endwin();
	return 0;
}

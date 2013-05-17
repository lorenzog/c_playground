#include <ncurses.h>

int main()
{	
	initscr();			/* Start curses mode 		  */
	int i;
	for ( i = 0 ; i < 10 ; i++ )
	{
		mvprintw(0,0,"i: %d", i);
		refresh();			/* Print it on to the real screen */
		sleep(1);
	}
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
}

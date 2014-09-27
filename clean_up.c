/* ----------------------------------------------------------------------------
 * clean_up.c
 *
 * Contains the definition of the clean_up() function.
 * Cleans (frees) up the allocated memory used by the program.
 *
 * Marvin Elsen, 27.09.2014
 * --------------------------------------------------------------------------*/
#include "game_functions.h"

void clean_up( sfRenderWindow* window, CELL cells[] )
{
	int y;
	for ( y = 0; y < CELL_COUNT_Y; y++ )
	{
		int x;
		for ( x = 0; x < CELL_COUNT_X; x++ )
		{
			sfRectangleShape_destroy( cells[y * CELL_COUNT_X + x].rect );
		}
	}
	sfRenderWindow_destroy( window );
}

/* ----------------------------------------------------------------------------
 * main.c
 *
 * Contains the main function and the game loop.
 *
 * Marvin Elsen, 27.09.2014
 * --------------------------------------------------------------------------*/
#include <stdio.h>
#include "game_functions.h"

int main( int argc, char** argv )
{
	sfVideoMode			mode	= { WIDTH, HEIGHT, 32 };
	sfRenderWindow*		window	= NULL;

	sfEvent				event;

	CELL				cells[CELL_COUNT_X * CELL_COUNT_Y];

	bool simulate = false;

	window = sfRenderWindow_create( mode, "Conway's Game of Life", sfClose, NULL );
	if ( !window )
		return 1;

	sfRenderWindow_setFramerateLimit( window, 30 );

	initiliaze_cells( cells );

	while ( sfRenderWindow_isOpen( window ) )
	{
		handle_input( window, &event, cells, &simulate );

		if ( simulate == true )
			update( cells );

		render( window, cells );
	}

	clean_up( window, cells );

	return 0;
}

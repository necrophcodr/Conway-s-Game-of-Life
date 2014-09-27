/* ----------------------------------------------------------------------------
 * render.c
 *
 * Contains the definition of the render() function.
 * Used to clean the screen and display the rectangles(cells).
 *
 * Marvin Elsen, 27.09.2014
 * --------------------------------------------------------------------------*/
#include "game_functions.h"

void render( sfRenderWindow* window, CELL cells[] )
{
	sfRenderWindow_clear( window, sfBlack );

	int y;
	for ( y = 0; y < CELL_COUNT_Y; y++ )
	{
		int x;
		for ( x = 0; x < CELL_COUNT_X; x++ )
		{
			sfRenderWindow_drawRectangleShape( window, cells[y * CELL_COUNT_X + x].rect, NULL );
		}
	}

	sfRenderWindow_display( window );
}

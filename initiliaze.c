/* ----------------------------------------------------------------------------
 * initiliaze.c
 *
 * Contains the definition of the initiliaze_cells() function.
 * Initiliazes the rectangles, aka, creates them, positions them and resizes
 * them.
 *
 * Marvin Elsen, 27.09.2014
 * --------------------------------------------------------------------------*/
#include "game_functions.h"

void initiliaze_cells( CELL cells[] )
{
	int y;
	for ( y = 0; y < CELL_COUNT_Y; y++ )
	{
		int x;
		for ( x = 0; x < CELL_COUNT_X; x++ )
		{
			cells[y * CELL_COUNT_X + x].rect = sfRectangleShape_create();

			sfVector2f	position	= { x * CELL_SIZE, y * CELL_SIZE  };
			sfVector2f	size		= { CELL_SIZE, CELL_SIZE  };
			sfColor		color		= { 255, 255, 255, 255 };

			sfRectangleShape_setPosition( cells[y * CELL_COUNT_X + x].rect, position );
			sfRectangleShape_setSize( cells[y * CELL_COUNT_X + x].rect, size );
			sfRectangleShape_setFillColor( cells[y * CELL_COUNT_X + x].rect, color );
		}
	}
}

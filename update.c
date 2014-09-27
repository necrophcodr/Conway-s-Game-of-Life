/* ----------------------------------------------------------------------------
 * update.c
 *
 * Contains the definition of the update() function.
 * Processes the game logic, e.g. whether the cells are alive or dead.
 *
 * Marvin Elsen, 27.09.2014
 * --------------------------------------------------------------------------*/
#include "game_functions.h"

void update( CELL cells[] )
{
	CELL* cells_marked_for_live[CELL_COUNT_X * CELL_COUNT_Y]	= {NULL};
	CELL* cells_marked_for_death[CELL_COUNT_X * CELL_COUNT_Y]	= {NULL};

	int marked_death_cells_count	= 0;
	int marked_live_cells_count		= 0;

	int y;
	for ( y = 0; y < CELL_COUNT_Y; y++ )
	{
		int x;
		for ( x = 0; x < CELL_COUNT_X; x++ )
		{
			int amount_of_neighbours_alive = get_neighbours_alive( cells, y, x );

			if ( cells[y * CELL_COUNT_X + x].live_state == ALIVE )
			{
				if ( amount_of_neighbours_alive < 2 || amount_of_neighbours_alive > 3 )
					cells_marked_for_death[marked_death_cells_count++] = &cells[y * CELL_COUNT_X + x];
			}
			else
			{
				if ( amount_of_neighbours_alive == 3 )
					cells_marked_for_live[marked_live_cells_count++] = &cells[y * CELL_COUNT_X + x];
			}
		}
	}

	int i;
	for ( i = 0; i < marked_death_cells_count; i++ )
	{
		cell_die( cells_marked_for_death[i] );
	}

	for ( i = 0; i < marked_live_cells_count; i++ )
	{
		cell_live( cells_marked_for_live[i] );
	}
}

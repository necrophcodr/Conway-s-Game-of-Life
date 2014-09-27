/* ----------------------------------------------------------------------------
 * cell.c
 *
 * Contains cell handling stuff.
 *
 * Marvin Elsen, 27.09.2014
 * --------------------------------------------------------------------------*/
#include "cell.h"

void cell_live( CELL* cell )
{
	cell->live_state = ALIVE;

	sfColor color = { 0, 0, 0, 255 };
	sfRectangleShape_setFillColor( cell->rect, color );
}

void cell_die( CELL* cell )
{
	cell->live_state = DEAD;

	sfColor color = { 255, 255, 255, 255 };
	sfRectangleShape_setFillColor( cell->rect, color );
}

int get_neighbours_alive( CELL cells[], int y, int x )
{
	int cells_alive = 0;
	int y_add;
	for ( y_add = -1; y_add <= 1;  y_add++ )
	{
		int x_add;
		for ( x_add = -1; x_add <= 1; x_add++ )
		{
			int index = (y+y_add) * CELL_COUNT_X + (x+x_add);
			if ( index >= 0 && index < CELL_COUNT_X * CELL_COUNT_Y )
			{
				if ( cells[ index ].live_state == ALIVE &&
					 !(y_add == 0 && x_add == 0) )
				{
					cells_alive++;
				}
			}
		}
	}

	return cells_alive;
}

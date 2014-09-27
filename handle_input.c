/* ----------------------------------------------------------------------------
 * handle_input.c
 *
 Contains the definition of the handle_input() function.
 * Grabs the user's input and processes it.
 *
 * Marvin Elsen, 27.09.2014
 * --------------------------------------------------------------------------*/
#include "game_functions.h"

void handle_input( sfRenderWindow* window, sfEvent* event, CELL cells[], bool* simulate )
{
	while ( sfRenderWindow_pollEvent( window, event ) )
	{
		switch ( event->type )
		{
			case sfEvtClosed:
				sfRenderWindow_close( window );
				break;
			case sfEvtKeyPressed:
				if ( sfKeyboard_isKeyPressed( sfKeyA ) )
				{
					if ( *simulate == true )
						*simulate = false;
					else
						*simulate = true;
				}
				break;
			case sfEvtMouseButtonPressed:
				if ( event->mouseButton.button == sfMouseLeft )
					cell_live( &cells[ (int)(event->mouseButton.y/CELL_SIZE) * CELL_COUNT_X + (int)(event->mouseButton.x/CELL_SIZE)] );
			default:
				break;
		}
	}
}

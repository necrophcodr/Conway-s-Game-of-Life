#include <stdio.h>
#include <SFML/Graphics.h>

#define WIDTH 		1024
#define HEIGHT 		768
#define CELL_SIZE 	16

typedef enum state {
	DEAD,
	ALIVE
} STATE;

void game_loop( sfRenderWindow* window, sfEvent* event )
{
	while ( sfRenderWindow_isOpen( window ) )
	{
		while ( sfRenderWindow_pollEvent( window, event ) )
		{
			if ( event->type == sfEvtClosed )
				sfRenderWindow_close( window );
		}

		sfRenderWindow_clear( window, sfBlack );

		sfRenderWindow_display( window );
	}
}

int main( int argc, char** argv )
{
	sfVideoMode 	mode 	= {WIDTH, HEIGHT, 32};
	sfRenderWindow* window 	= NULL;

	sfEvent 		event;

	STATE 			cells[WIDTH / CELL_SIZE][HEIGHT / CELL_SIZE] = {DEAD};

	window = sfRenderWindow_create( mode, "Conway's Game of Life", sfClose, NULL );
	if ( !window )
		return 1;

	sfRenderWindow_setFramerateLimit( window, 30 );

	game_loop( window, &event );

	sfRenderWindow_destroy( window );

	return 0;
}

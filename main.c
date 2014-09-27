#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <SFML/Graphics.h>

#define WIDTH 		1024
#define HEIGHT 		768
#define CELL_SIZE 	16

typedef enum state {
	DEAD,
	ALIVE
} STATE;

void game_loop( sfRenderWindow* window, sfEvent* event, sfRectangleShape* rectangles[] )
{
	while ( sfRenderWindow_isOpen( window ) )
	{
		while ( sfRenderWindow_pollEvent( window, event ) )
		{
			if ( event->type == sfEvtClosed )
				sfRenderWindow_close( window );
		}

		sfRenderWindow_clear( window, sfBlack );

		int i;
		for ( i = 0; i < HEIGHT / CELL_SIZE; i++ )
		{
			int j;
			for ( j = 0; j < WIDTH / CELL_SIZE; j++ )
			{
				sfRenderWindow_drawRectangleShape( window, rectangles[i * WIDTH/CELL_SIZE + j], NULL );
			}
		}

		sfRenderWindow_display( window );
	}
}

int main( int argc, char** argv )
{
	sfVideoMode 	mode 	= {WIDTH, HEIGHT, 32};
	sfRenderWindow* window 	= NULL;

	sfEvent 		event;

	STATE 			cells[WIDTH / CELL_SIZE][HEIGHT / CELL_SIZE] = {DEAD};
	sfRectangleShape*	rectangles[(WIDTH / CELL_SIZE) * (HEIGHT / CELL_SIZE)];

	srand( 10 );

	int i;
	for ( i = 0; i < HEIGHT / CELL_SIZE; i++ )
	{
		int j;
		for ( j = 0; j < WIDTH / CELL_SIZE; j++ )
		{
			rectangles[i * WIDTH/CELL_SIZE + j] = sfRectangleShape_create();
			if ( !rectangles[i * WIDTH/CELL_SIZE +j] )
				return 2;
			sfVector2f 	position 	= { j * CELL_SIZE, i * CELL_SIZE  };
			sfVector2f 	size 		= { CELL_SIZE, CELL_SIZE  };
			sfColor 	color		= { 1+rand()%255, 1+rand()%255, 1+rand()%255, 255 };

			sfRectangleShape_setPosition( rectangles[i * WIDTH/CELL_SIZE + j], position );
			sfRectangleShape_setSize( rectangles[i * WIDTH/CELL_SIZE + j], position );
			sfRectangleShape_setFillColor( rectangles[i * WIDTH/CELL_SIZE + j], color );
		}
	}

	window = sfRenderWindow_create( mode, "Conway's Game of Life", sfClose, NULL );
	if ( !window )
		return 1;

	sfRenderWindow_setFramerateLimit( window, 30 );

	game_loop( window, &event, rectangles );

	for ( i = 0; i < HEIGHT / CELL_SIZE; i++ )
	{
		int j;
		for ( j = 0; j < WIDTH / CELL_SIZE; j++ )
		{
			sfRectangleShape_destroy( rectangles[i * WIDTH/CELL_SIZE + j] );
		}
	}

	sfRenderWindow_destroy( window );

	return 0;
}

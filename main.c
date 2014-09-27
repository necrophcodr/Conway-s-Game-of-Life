#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.h>

#define WIDTH			1024
#define HEIGHT			768

#define CELL_SIZE		16

#define CELL_COUNT_X	WIDTH / CELL_SIZE
#define CELL_COUNT_Y	HEIGHT / CELL_SIZE

typedef enum state {
	DEAD,
	ALIVE
} STATE;

void initiliaze( sfRectangleShape* rectangles[] )
{
	srand( 10 );

	int y;
	for ( y = 0; y < CELL_COUNT_Y; y++ )
	{
		int x;
		for ( x = 0; x < CELL_COUNT_X; x++ )
		{
			rectangles[y * CELL_COUNT_X + x] = sfRectangleShape_create();
			if ( !rectangles[y * CELL_COUNT_X + x] )
				return 1;

			sfVector2f	position	= { x * CELL_SIZE, y * CELL_SIZE  };
			sfVector2f	size		= { CELL_SIZE, CELL_SIZE  };
			sfColor		color		= { 1+rand()%255, 1+rand()%255, 1+rand()%255, 255 };

			sfRectangleShape_setPosition( rectangles[y * CELL_COUNT_X + x], position );
			sfRectangleShape_setSize( rectangles[y * CELL_COUNT_X + x], size );
			sfRectangleShape_setFillColor( rectangles[y * CELL_COUNT_X + x], color );
		}
	}
}

void handle_input( sfRenderWindow* window, sfEvent* event )
{
	while ( sfRenderWindow_pollEvent( window, event ) )
	{
		if ( event->type == sfEvtClosed )
			sfRenderWindow_close( window );
	}
}

void update()
{
}

void clean_up( sfRenderWindow* window, sfRectangleShape* rectangles[] )
{
	int y;
	for ( y = 0; y < CELL_COUNT_Y; y++ )
	{
		int x;
		for ( x = 0; x < CELL_COUNT_X; x++ )
		{
			sfRectangleShape_destroy( rectangles[y * CELL_COUNT_X + x] );
		}
	}
	sfRenderWindow_destroy( window );
}

void render( sfRenderWindow* window, sfRectangleShape* rectangles[] )
{
	sfRenderWindow_clear( window, sfBlack );

	int y;
	for ( y = 0; y < CELL_COUNT_Y; y++ )
	{
		int x;
		for ( x = 0; x < CELL_COUNT_X; x++ )
		{
			sfRenderWindow_drawRectangleShape( window, rectangles[y * CELL_COUNT_X + x], NULL );
		}
	}

	sfRenderWindow_display( window );
}

int main( int argc, char** argv )
{
	sfVideoMode			mode	= { WIDTH, HEIGHT, 32 };
	sfRenderWindow*		window	= NULL;

	sfEvent				event;

	STATE				cells[CELL_COUNT_X * CELL_COUNT_Y]		= { DEAD };
	sfRectangleShape*	rectangles[CELL_COUNT_X * CELL_COUNT_Y]	= { NULL };

	window = sfRenderWindow_create( mode, "Conway's Game of Life", sfClose, NULL );
	if ( !window )
		return 1;

	sfRenderWindow_setFramerateLimit( window, 30 );

	initiliaze( rectangles );

	while ( sfRenderWindow_isOpen( window ) )
	{
		handle_input( window, &event );

		update();

		render( window, rectangles );

	}

	clean_up( window, rectangles );

	return 0;
}

/* ----------------------------------------------------------------------------
 * game_functions.h
 *
 * Contains the functions that make up the game loop.
 *
 * Marvin Elsen, 27.09.2014
 * --------------------------------------------------------------------------*/
#ifndef _GAME_FUNCTIONS_H_
#define _GAME_FUNCTIONS_H_

#include "common.h"
#include "cell.h"

/* initiliaze_cells() is used to create and position and resize the
 * rectangles representing the cells */
void initiliaze_cells( CELL[] );

/* handle_input() is used to handle user input */
void handle_input( sfRenderWindow*, sfEvent*, CELL[], bool* );

/* update() contains the game logic */
void update();

/* render() is used to render the rectangles(cells) to the screen and clear the
 * screen each frame */
void render( sfRenderWindow*, CELL[] );

/* clean_up is used to free the memory */
void clean_up( sfRenderWindow*, CELL[] );

#endif

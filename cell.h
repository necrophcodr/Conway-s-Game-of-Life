/* ----------------------------------------------------------------------------
 * cell.h
 *
 * Contains cell handling stuff.
 *
 * Marvin Elsen, 27.09.2014
 * --------------------------------------------------------------------------*/
#ifndef _CELL_H_
#define _CELL_H_

#define CELL_SIZE		16

#define CELL_COUNT_X	WIDTH / CELL_SIZE
#define CELL_COUNT_Y	HEIGHT / CELL_SIZE

#include "common.h"

enum state {
	DEAD,
	ALIVE
};

typedef struct cell_t {
	enum state			live_state;
	sfRectangleShape*	rect;
} CELL;

void cell_live( CELL* );
void cell_die( CELL* );
int get_neighbours_alive( CELL[], int, int );

#endif

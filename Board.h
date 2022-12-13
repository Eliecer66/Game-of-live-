/*
 * Board.h
 *
 *  Created on: 29/08/2022
 *      Author: algo2
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Cellule.h"
using namespace std;

static const int MAX_FIL = 20;
static const int MAX_COL = 80;
static const int MAX_COORDINATE = 1600;
static const int ON = 3;

typedef struct {
	int x;
	int y;
} Coordinate;

typedef struct {
	Cellule dashBoard[MAX_FIL][MAX_COL];
} Board;

/*
 * PRE-CONDITIONS: Receive a struct, by reference, which contain the information of the board to be loaded.
 * POST-CONDITIONS: It Loads the information received to the board. Returns 1 if was charge successfully
 */
int loadBoard(Board &board, Coordinate coordinate[MAX_COORDINATE], int size);

/*
 * PRE-CONDITIONS: Receive a struct, by reference, an array, and integers that handles the info to the stats.
 * POST-CONDITIONS: Introduce the game to the user
 */
void parseBoard(Board &board, Coordinate coordinate[MAX_COORDINATE], int &size, int &newBorn, int &newDead);


/*
 * PRE-CONDITIONS: Receive a struct, by reference, which contain the information of the board.
 * POST-CONDITIONS: Show the board through the console.
 */
void showBoard(Board board);



#endif /* BOARD_H_ */

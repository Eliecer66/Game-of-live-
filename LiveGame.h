/*
 * liveGame.h
 *
 *  Created on: 29/08/2022
 *      Author: algo2
 */

#ifndef LIVEGAME_H_
#define LIVEGAME_H_

#include <string>
#include <iostream>
#include "Board.h"

using namespace std;

typedef struct {
	int onCells;
	int newBorn;
	int deadCells;
	double averageBirth;
	double deathRate;
	bool freeze;
} Stats;

typedef struct {
	Board board;
	Stats stats;
} LiveGame;

/*
 * PRE-CONDITIONS:
 * POST-CONDITIONS: Introduce the game to the user.
 */
char wellcomeMessage();

/*
 * PRE-CONDITIONS: Receive a struct which has the whole information about the game to initilaize.
 * POST-CONDITIONS: Initialize all of the variables.
 */
void initializeGame(LiveGame &liveGame, char start);

/*
 * PRE-CONDITIONS: Receive a struct, by value, which has the whole information about the game
 * POST-CONDITIONS: Show the game through the console.
 */
void showGame(LiveGame liveGame);

/*
 * PRE-CONDITIONS: Receive a struct, by reference, which has the whole information about the game
 * POST-CONDITIONS: It is in charge to parse and render the right flow of the game.
 */
void flowGame(LiveGame &liveGame);

/*
 * PRE-CONDITIONS: Receive a struct, by reference, which has the whole information about the game
 * POST-CONDITIONS: It is wrap up the game and show a message through the console.
 */
void finishGame(LiveGame &liveGame);


#endif /* LIVEGAME_H_ */

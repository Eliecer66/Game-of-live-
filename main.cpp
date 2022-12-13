/*
 * main.cpp
 *
 *  Created on: 29/08/2022
 *      Author: algo2
 */

#include "LiveGame.h"
using namespace std;

int main () {

	LiveGame liveGame;
	char start = wellcomeMessage();

	initializeGame(liveGame, start);
	showGame(liveGame);
	flowGame(liveGame);
	finishGame(liveGame);

	return 0;

}

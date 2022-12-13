/*
 * Board.cpp
 *
 *  Created on: 29/08/2022
 *      Author: algo2
 */

#include "Board.h"
#include "Cellule.h"
#include <iostream>
using namespace std;

int loadBoard(Board &board, Coordinate coordinate[MAX_COORDINATE], int size) {

	for (int i = 0; i < MAX_FIL; i++) {
		for (int j = 0; j < MAX_COL; j++) {

			initializeCellule(board.dashBoard[i][j]);
		}
	}

	for (int i = 0; i < size; i++) {

		changeStatus(board.dashBoard[coordinate[i].x][coordinate[i].y], On);
	}

	return 0;
}

void showBoard(Board board) {

	for (int i = 0; i < MAX_FIL; i++) {

		cout << "\t\t\t\t\t";
		for (int j = 0; j < MAX_COL; j++) {

			cout << board.dashBoard[i][j].character;
		}
		cout <<"\n";
	}
	cout << "\n";
}

bool parseNeighbour(Board board, int iStart, int jStart) {

	int celluleCounter = 0;
	bool on = false;

	for (int i = (iStart - 1); i <= (iStart + 1); i++) {

		for (int j = (jStart - 1); j <= (jStart + 1); j++) {

			if ((i >= 0 && i < MAX_FIL) && (j >= 0 && j < MAX_COL)) {

				if (!(i == iStart && j == jStart)) {

					if (getStatus(board.dashBoard[i][j]) == On) {

						celluleCounter++;
					}
				}
			}

		}
	}

	if (celluleCounter == ON) {

		on = true;
	}

	return on;
}

void parseBoard(Board &board, Coordinate coordinate[MAX_COORDINATE], int &size, int &newBorn, int &newDead) {

	for (int i = 0; i < MAX_FIL; i++) {

		for (int j = 0; j < MAX_COL; j++) {

			if (parseNeighbour(board, i, j)) {

				if (board.dashBoard[i][j].state == Off) {

					newBorn++;
				}

				coordinate[size].x = i;
				coordinate[size].y = j;
				size++;

			} else {

				if (board.dashBoard[i][j].state == On) {

					newDead++;

				}
			}
		}
	}

	loadBoard(board, coordinate, size);
}

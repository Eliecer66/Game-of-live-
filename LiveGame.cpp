/*
 * liveGame.cpp
 *
 *  Created on: 29/08/2022
 *      Author: algo2
 */

#include "LiveGame.h"
#include "Board.h"
using namespace std;

static const string MARGEN = "\t\t\t";
static const char PURSUE = 'y';
static const char RESET = 'r';
static const string FREEZING = "CONGELADO";
static const string RUNING = "ACTUALIZADO";
static const int PERCENT = 100;
static const int FREEZ = 2;

void instructions() {

	cout << "\t\t\t\t\t\t\t\t Instrucciones\n" << endl;
	cout << MARGEN << "1. Tiene que ingresar las coordenadas de la celulas que estarán vivas. Puede ingresar hasta 1600 celulas." << endl;
	cout << MARGEN << "2. Ingresa las coordenadas pedidas y selecciona si quiere o no seguir posicionando celulas." << endl;
	cout << MARGEN << "3. En cada turno tendra la opcion de continuar, reiniciar, o finalizar." << endl;
	cout << MARGEN << "4. Podra ver segun avance el juego el estado de las celulas y informacion entre otros datos.\n\n" << endl;
}

char wellcomeMessage() {

	char next;

	cout << "\n\t\t\t\t\t\t\t Bienvenido al juego de la vida\n" <<endl;

	cout << MARGEN << "El juego de la vida es un juego de cero jugadores, lo que quiere decir que su evolucion está determinada" << endl;
	cout << MARGEN << "por el estado inicial y no necesita ninguna entrada de datos posterio. El tablero de juego es una malla" << endl;
	cout << MARGEN << "formada por cuadrados 'celulas', cada celula puede terner hasta 8 celulas vecinas que son las que estan" << endl;
	cout << MARGEN << "proximas a ella el estado evoluciona a lo largo de unidades de tiempo discretas, por turnos, en donde" << endl;
	cout << MARGEN << "una celula esta viva si tiene 3 celulas vecinas vivas, si esta viva se mantiene viva, si esta muerta " << endl;
	cout << MARGEN << "nace. De lo contrario muere ya sea por sobre poblacion o soledad.\n\n" << endl;

	instructions();

	cout << MARGEN << "Si esta listo para iniciar el juego presione 'y': ";

	cin >> next;
	cout << "\n";
	return next;
}

Coordinate requestCoordinates() {

	Coordinate coordinate;
	cout << MARGEN << "Ingrese cordenada para fila: ";
	cin >> coordinate.x;
	cout << MARGEN << "Ingrese cordenada para columna: ";
	cin >> coordinate.y;
	return coordinate;
}

void getCoordinate(Coordinate coordinate[MAX_COORDINATE], int &size) {

	char keep = PURSUE;

	while (size < MAX_COORDINATE && keep == PURSUE) {

		coordinate[size] = requestCoordinates();
		size++;
		cout << MARGEN << "Cantidad de celulas vivas posicionadas:" << size <<"\n\n" << MARGEN << "¿Quiere seguir llenando? Presione 'y': ";
		cin >> keep;

	}
}

void initializeStats(Stats &stats, int size) {

	stats.newBorn = size;
	stats.averageBirth = 0;
	stats.deadCells = MAX_COORDINATE - size;
	stats.freeze = false;
	stats.onCells = size;
	stats.deathRate = 0;

}

void initializeGame(LiveGame &liveGame, char start) {

	Coordinate coordinate[MAX_COORDINATE];
	int size = 0;
	if (start == PURSUE) {

		getCoordinate(coordinate, size);

	}

	loadBoard(liveGame.board, coordinate, size);
	initializeStats(liveGame.stats, size);
}

void showStats(Stats stats) {

	string message = RUNING;

	if (stats.freeze) {
		message = FREEZING;
	}

	cout << MARGEN << "- Nuevos nacimientos: " << stats.newBorn << endl;
	cout << MARGEN << "- Celulas vivas: " << stats.onCells << endl;
	cout << MARGEN << "- Celulas muertas: " << stats.deadCells << endl;
	cout << MARGEN << "- Promedio de nacimientos: " << stats.averageBirth << "%" << endl;
	cout << MARGEN << "- Promedio de muerte: " << stats.deathRate  << "%" << endl;
	cout << MARGEN << "- El juego se congelo despues de dos turnos: " << message << "\n" << endl;
}

void showGame(LiveGame liveGame) {

	showStats(liveGame.stats);
	showBoard(liveGame.board);
}


bool isFreez(int size, int previous, int &counterFreez) {

	bool freez = false;

	if (size == previous) {

		counterFreez++;

		if (counterFreez == FREEZ) {

			freez = true;
		}
	}

	return freez;
}

void parseStats(Stats &stats, int size, int newBorn, int newDead, int previous, int &counterFreez) {

	stats.deadCells = MAX_COORDINATE - size;
	stats.onCells = size;
	stats.averageBirth =  ((double)newBorn * PERCENT) / MAX_COORDINATE;
	stats.deathRate = ((double)newDead * PERCENT) / MAX_COORDINATE;
	stats.newBorn = newBorn;
	stats.freeze = isFreez(size, previous, counterFreez);
}

void updateGame(LiveGame &liveGame, int &size, int &counterFreez) {

	Coordinate coordinate[MAX_COORDINATE];
	int previous = size;
	size = 0;
	int newBorn = 0;
	int newDead = 0;

	parseBoard(liveGame.board, coordinate, size, newBorn, newDead);
	parseStats(liveGame.stats, size, newBorn, newDead, previous, counterFreez);
}

char requestAction() {

	char action;
	cout << MARGEN << "- Para continuar: y." << endl;
	cout << MARGEN << "- Para finalizar: n." << endl;
	cout << MARGEN << "- Para reiniciar: r. " << endl;
	cout << MARGEN << "Elija una opcion: ";
	cin >> action;
	cout << " " << endl;

	return action;

}

void resetGame(LiveGame &liveGame, char start) {

	cout << MARGEN << "SE HA REINICIADO EL JUEGO." << endl;
	instructions();
	initializeGame(liveGame, start);

}

void flowGame(LiveGame &liveGame) {

	int size;
	int counterFreez = 0;
	char action = requestAction();

	while (action == PURSUE) {

		updateGame(liveGame, size, counterFreez);
		showGame(liveGame);
		action = requestAction();

		if (action == RESET) {

			resetGame(liveGame, PURSUE);
			action = PURSUE;

		}
	}
}

void finishGame(LiveGame &liveGame) {

	LiveGame wrapUp;
	liveGame = wrapUp;
	cout << MARGEN << "EL JUEGO HA TERMINAO" << endl;

}
/*
 * Cellule.cpp
 *
 *  Created on: 29/08/2022
 *      Author: algo2
 */

#include "Cellule.h"

void initializeCellule(Cellule &cellule) {

	cellule.character = DESABLED;
	cellule.state = Off;
}

void changeStatus(Cellule &cellule, Status status) {

	if (status == On) {

		cellule.character = ACTIVE;

	} else {

		cellule.character = DESABLED;
	}

	cellule.state = status;
}

Status getStatus(Cellule cellule) {

	Status state;

	if (cellule.state == On) {

		state = On;

	} else {

		state = Off;

	}

	return state;
}



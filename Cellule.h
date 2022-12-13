/*
 * Cellule.h
 *
 *  Created on: 29/08/2022
 *      Author: algo2
 */

#ifndef CELLULE_H_
#define CELLULE_H_

static const char ACTIVE = 'I';
static const char DESABLED  = 'O';

enum Status {
	On,
	Off
};

typedef struct {
	Status state;
	char character;
}Cellule;

/*
 * PRE-CONDITIONS: Game start
 * POST-CONDITIONS: Introduce the game to the user
 */
void initializeCellule(Cellule &cellule);

/*
 * PRE-CONDITIONS: Game start
 * POST-CONDITIONS: Introduce the game to the user
 */
void changeStatus(Cellule &cellule, Status status);

/*
 * PRE-CONDITIONS: Game start
 * POST-CONDITIONS: Introduce the game to the user
 */
Status getStatus(Cellule cellule);

#endif /* CELLULE_H_ */

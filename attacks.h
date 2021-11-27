#ifndef ATTACKS_H
#define ATTACKS_H

#include <iostream>

#include "players.h"
#include "monsters.h"

int getRandomNumber(int, int);

void pAttack(Player&, Monster&);
void mAttack(Player&, Monster&);

#endif /* ATTACKS_H */

#include "stdafx.h"

#include "attacks.h"

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + (int)((max - min + 1) * (rand() * fraction));
}

void pAttack(Player& hero, Monster& monst) {
	int pDmg;

	if (!hero.GetCurWpn().GetIsItem()) { // if no wpn equipped
		pDmg = (getRandomNumber(0, hero.GetPlayerDamage())) - (getRandomNumber(0, monst.GetMonsterArmorClass()));
		//pDmg = (rand() % (hero.GetPlayerDamage() + 1)) - (rand() % (monst.GetMonsterArmorClass() + 1)); // (rand (dmg + 1)) - rand monster ac
	} else {
		pDmg = (getRandomNumber(1, hero.GetPlayerDamage())) - (getRandomNumber(0, monst.GetMonsterArmorClass()));
		//pDmg = ((rand() % hero.GetPlayerDamage()) + 1) - (rand() % (monst.GetMonsterArmorClass() + 1)); // ((rand dmg) + 1) - rand monster ac
	}

	if (pDmg < 0) // don't heal the monster
		pDmg = 0;

	monst.SetLife(monst.GetLife() - pDmg); // deal player damage

	if (!hero.GetCurWpn().GetIsItem()) { // if no wpn equipped
		std::cout << "You damage the monster with your fists for " << pDmg << std::endl; // print damage message
	}
	else {
		std::cout << "You damage the monster with your " << hero.GetCurWpn().GetItemNameStr() << " for " << pDmg << std::endl; // print damage message
	}
}

void mAttack(Player& hero, Monster& monst) {
	int mDmg = (getRandomNumber(1, monst.GetMonsterDamage())) - (getRandomNumber(0, hero.GetPlayerArmorClass()));
	//int mDmg = ((rand() % monst.GetMonsterDamage()) + 1) - (rand() % (hero.GetPlayerArmorClass() + 1)); // ((rand dmg) + 1) - rand player ac

	if (mDmg < 0) // don't heal the player
		mDmg = 0;

	hero.SetLife(hero.GetLife() - mDmg); // deal monster damage

	std::cout << "The monster damages you for " << mDmg << std::endl; // print damage message
}

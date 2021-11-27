#ifndef MONSTERS_H
#define MONSTERS_H

#include <iostream>

class Monster {

	int life;
	int maxLife;
	int vit;
	int intel;
	int str;
	int dex;
	int lvl;
	int exp;
	int damage;
	int armorClass;

	void InitStats();

public:

	Monster();

	int GetLife();
	int GetMaxLife();
	int GetVit();
	int GetIntel();
	int GetStr();
	int GetDex();
	int GetLvl();
	int GetExp();
	int GetMonsterDamage();
	int GetMonsterArmorClass();

	void SetLife(int);
	void SetMaxLife(int);
	void SetVit(int);
	void SetIntel(int);
	void SetStr(int);
	void SetDex(int);
	void SetLvl(int);
	void SetExp(int);
	void SetMonsterDamage(int);
	void SetMonsterArmorClass(int);

};

#endif /* MONSTERS_H */

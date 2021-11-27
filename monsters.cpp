#include "stdafx.h"

#include "monsters.h"

// private

void Monster::InitStats() {

	maxLife = 10;
	life = maxLife;
	vit = 0;
	intel = 0;
	str = 0;
	dex = 0;
	lvl = 1;
	exp = 1;
	damage = 4;
	armorClass = 1;
}

// public

Monster::Monster() { InitStats(); }

int Monster::GetLife() { return life; }
int Monster::GetMaxLife() { return maxLife; }
int Monster::GetVit() { return vit; }
int Monster::GetIntel() { return intel; }
int Monster::GetStr() { return str; }
int Monster::GetDex() { return dex; }
int Monster::GetLvl() { return lvl; }
int Monster::GetExp() { return exp; }
int Monster::GetMonsterDamage() { return damage; }
int Monster::GetMonsterArmorClass() { return armorClass; }

void Monster::SetLife(int newLife) { life = newLife; }
void Monster::SetMaxLife(int newMaxLife) { maxLife = newMaxLife; }
void Monster::SetVit(int newVit) { vit = newVit; }
void Monster::SetIntel(int newIntel) { intel = newIntel; }
void Monster::SetStr(int newStr) { str = newStr; }
void Monster::SetDex(int newDex) { dex = newDex; }
void Monster::SetLvl(int newLvl) { lvl = newLvl; }
void Monster::SetExp(int newExp) { exp = newExp; }
void Monster::SetMonsterDamage(int newDamage) { damage = newDamage; }
void Monster::SetMonsterArmorClass(int newArmorClass) { armorClass = newArmorClass; }

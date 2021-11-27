#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include <string>

#include "enums.h"
#include "defines.h"
#include "items.h"

class Player {

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
	ItemObj curInv[NUMOFINVSLOTS];
	ItemObj curWpn;
	ItemObj curArmor;

	void InitStats();

public:

	Player();

	void PrintStats();

	int GetLife();
	int GetMaxLife();
	int GetVit();
	int GetIntel();
	int GetStr();
	int GetDex();
	int GetLvl();
	int GetExp();
	int GetPlayerDamage();
	int GetPlayerArmorClass();

	int GetFirstEmptyInvSlot();

	ItemObj GetCurInv(int);
	ItemObj GetCurWpn();
	ItemObj GetCurArmor();

	void SetLife(int);
	void SetMaxLife(int);
	void SetVit(int);
	void SetIntel(int);
	void SetStr(int);
	void SetDex(int);
	void SetLvl(int);
	void SetExp(int);
	void SetPlayerDamage(int);
	void SetPlayerArmorClass(int);

	void SetCurInv(int, ItemObj);
	void SetCurWpn(ItemObj);
	void SetCurArmor(ItemObj);

	void EquipItem(int);
	void UnEquipWpn();
	void UnEquipArmor();
	void DropItem(int);

};

#endif /* PLAYERS_H */

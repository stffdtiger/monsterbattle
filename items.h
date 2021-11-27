#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>

#include "enums.h"
#include "defines.h"

class ItemObj {

	bool isItem;
	std::string nameStr;
	ItemName name;
	int weight;
	int test;
	ItemType type;
	int damage;
	int armorClass;

	void InitStats();

public:

	ItemObj();

	void SetItem(ItemName);

	void SetTest();

	bool GetIsItem();
	std::string GetItemNameStr();
	ItemName GetItemName();
	int GetItemWeight();
	int GetItemTest();
	ItemType GetItemType();
	int GetItemDamage();
	int GetItemArmorClass();

};

#endif /* ITEMS_H */

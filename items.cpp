#include "stdafx.h"

#include "items.h"

// private

void ItemObj::InitStats() {
	isItem = false;
	nameStr = "No Item";
	name = noitem;
	weight = 100;
	test = rand() % weight;
	type = none;
	damage = 0;
	armorClass = 0;
}

// public

ItemObj::ItemObj() { InitStats(); }

void ItemObj::SetItem(ItemName item) {
	switch (item) {
	case woodensword:
		isItem = true;
		nameStr = "Wooden Sword";
		name = woodensword;
		weight = 50;
		test = rand() % weight;
		type = weapon;
		damage = 1;
		armorClass = 0;
		break;

	case ironsword:
		isItem = true;
		nameStr = "Iron Sword";
		name = ironsword;
		weight = 15;
		test = rand() % weight;
		type = weapon;
		damage = 3;
		armorClass = 0;
		break;

	case leatherarmor:
		isItem = true;
		nameStr = "Leather Armor";
		name = leatherarmor;
		weight = 20;
		test = rand() % weight;
		type = armor;
		damage = 0;
		armorClass = 1;
		break;

	case ringmail:
		isItem = true;
		nameStr = "Ring Mail";
		name = ringmail;
		weight = 5;
		test = rand() % weight;
		type = armor;
		damage = 0;
		armorClass = 3;
		break;

	default:
		isItem = false;
		nameStr = "No Item";
		name = noitem;
		weight = 100;
		test = rand() % weight;
		type = none;
		damage = 0;
		armorClass = 0;
		break;
	}
}

bool ItemObj::GetIsItem() { return isItem; }
std::string ItemObj::GetItemNameStr() { return nameStr; }
ItemName ItemObj::GetItemName() { return name; }
int ItemObj::GetItemWeight() { return weight; }
int ItemObj::GetItemTest() { return test; }
ItemType ItemObj::GetItemType() { return type; }
int ItemObj::GetItemDamage() { return damage; }
int ItemObj::GetItemArmorClass() { return armorClass; }

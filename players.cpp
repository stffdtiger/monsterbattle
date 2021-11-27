#include "stdafx.h"

#include "players.h"

// private

void Player::InitStats() {

	vit = 10;
	maxLife = vit * 5;
	life = maxLife;
	intel = 1;
	str = 1;
	dex = 1;
	lvl = 1;
	exp = 0;
	damage = 3;
	armorClass = 0;

	for (int ii = 0; ii < NUMOFINVSLOTS; ii++) {
		curInv[ii] = ItemObj();
	}

	curWpn = ItemObj();
	curArmor = ItemObj();

}

// public

Player::Player() { InitStats(); }

int Player::GetLife() { return life; }
int Player::GetMaxLife() { return maxLife; }
int Player::GetVit() { return vit; }
int Player::GetIntel() { return intel; }
int Player::GetStr() { return str; }
int Player::GetDex() { return dex; }
int Player::GetLvl() { return lvl; }
int Player::GetExp() { return exp; }
int Player::GetPlayerDamage() { return damage; }
int Player::GetPlayerArmorClass() { return armorClass; }

int Player::GetFirstEmptyInvSlot() {
	for (int ii = 0; ii < NUMOFINVSLOTS; ii++) {
		if (!GetCurInv(ii).GetIsItem()) {
			return ii;
		}
	}
	return -1;
}

ItemObj Player::GetCurInv(int slot) { return curInv[slot]; }
ItemObj Player::GetCurWpn() { return curWpn; }
ItemObj Player::GetCurArmor() { return curArmor; }

void Player::SetLife(int newLife) { life = newLife; }
void Player::SetMaxLife(int newMaxLife) { maxLife = newMaxLife; }
void Player::SetVit(int newVit) { vit = newVit; }
void Player::SetIntel(int newIntel) { intel = newIntel; }
void Player::SetStr(int newStr) { str = newStr; }
void Player::SetDex(int newDex) { dex = newDex; }
void Player::SetLvl(int newLvl) { lvl = newLvl; }
void Player::SetExp(int newExp) { exp = newExp; }
void Player::SetPlayerDamage(int newDamage) { damage = newDamage; }
void Player::SetPlayerArmorClass(int newArmorClass) { armorClass = newArmorClass; }

void Player::SetCurInv(int slot, ItemObj newItem) { curInv[slot] = newItem; }
void Player::SetCurWpn(ItemObj newItem) { curWpn = newItem; }
void Player::SetCurArmor(ItemObj newItem) { curArmor = newItem; }

void Player::EquipItem(int invSlot) {
	ItemObj tempItem = GetCurInv(invSlot);

	switch (GetCurInv(invSlot).GetItemType()) {
	case weapon:
		SetCurInv(invSlot, GetCurWpn());
		SetPlayerDamage(GetPlayerDamage() - GetCurWpn().GetItemDamage());
		std::cout << std::endl;
		std::cout << "Unequipped: " << GetCurWpn().GetItemNameStr() << std::endl;
		SetCurWpn(tempItem);
		SetPlayerDamage(GetPlayerDamage() + GetCurWpn().GetItemDamage());
		std::cout << "Equipped: " << GetCurWpn().GetItemNameStr() << std::endl;
		break;

	case armor:
		SetCurInv(invSlot, GetCurArmor());
		SetPlayerArmorClass(GetPlayerArmorClass() - GetCurArmor().GetItemArmorClass());
		std::cout << std::endl;
		std::cout << "Unequipped: " << GetCurArmor().GetItemNameStr() << std::endl;
		SetCurArmor(tempItem);
		SetPlayerArmorClass(GetPlayerArmorClass() + GetCurArmor().GetItemArmorClass());
		std::cout << "Equipped: " << GetCurArmor().GetItemNameStr() << std::endl;
		break;

	default:
		std::cout << std::endl;
		std::cout << "There is no item in that inventory slot." << std::endl;
		break;
	}
}

void Player::UnEquipWpn() {
	int slot = GetFirstEmptyInvSlot();
	if (slot >= 0) {
		ItemObj tempItem = GetCurWpn();

		switch (GetCurWpn().GetItemType()) {
		case weapon:
			SetCurWpn(GetCurInv(slot));
			SetCurInv(slot, tempItem);
			SetPlayerDamage(GetPlayerDamage() - tempItem.GetItemDamage());
			std::cout << std::endl;
			std::cout << "Unequipped: " << GetCurInv(slot).GetItemNameStr() << std::endl;
			break;

		default:
			std::cout << std::endl;
			std::cout << "No weapon equipped." << std::endl;
			break;
		}
	}
	else {
		std::cout << std::endl;
		std::cout << "There are no empty inventory spaces." << std::endl;
	}
}

void Player::UnEquipArmor() {
	int slot = GetFirstEmptyInvSlot();
	if (slot >= 0) {
		ItemObj tempItem = GetCurArmor();

		switch (GetCurArmor().GetItemType()) {
		case armor:
			SetCurArmor(GetCurInv(slot));
			SetCurInv(slot, tempItem);
			SetPlayerArmorClass(GetPlayerArmorClass() - tempItem.GetItemArmorClass());
			std::cout << std::endl;
			std::cout << "Unequipped: " << GetCurInv(slot).GetItemNameStr() << std::endl;
			break;

		default:
			std::cout << std::endl;
			std::cout << "No armor equipped." << std::endl;
			break;
		}
	}
	else {
		std::cout << std::endl;
		std::cout << "There are no empty inventory spaces." << std::endl;
	}
}

void Player::DropItem(int invSlot) {
	if (!GetCurInv(invSlot).GetIsItem()) {
		std::cout << std::endl;
		std::cout << "There is no item in that inventory slot." << std::endl;
	}
	else {
		ItemObj tempItem = ItemObj();
		std::string droppedItemName = GetCurInv(invSlot).GetItemNameStr();
		SetCurInv(invSlot, tempItem);
		std::cout << std::endl;
		std::cout << "Dropped item: " << droppedItemName << std::endl;
	}
}

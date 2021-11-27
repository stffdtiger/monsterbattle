#include "stdafx.h"

// include
#include <Windows.h> // text color feature
#include <iostream> // cout cin
#include <sstream> // stringstream convert
#include <string> // string
#include <cstdlib> // srand rand
#include <ctime> // time
#include <cctype> // isdigit

// include
#include "items.h"
#include "players.h"
#include "monsters.h"
#include "attacks.h"
#include "defines.h"
#include "enums.h"

int GetInput() {

	std::string menuInputString;
	int menuInputInt;

	// Ask for input
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << std::endl;
	std::cout << "Type a selection number and press enter." << std::endl;
	std::cout << ">";
	getline(std::cin, menuInputString);

	if (menuInputString.length() == 1 && isdigit(menuInputString.at(0))) {
		std::stringstream toInt(menuInputString);
		if (!(toInt >> menuInputInt))
			return 0;
		else
			return menuInputInt;
	}
	else if (menuInputString.length() == 1 && menuInputString.at(0) == 'q')
		return -1;
	else
		return 0;

}

MenuLevel BadSelect(MenuLevel menuLevel) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << std::endl;
	std::cout << "You have typed an incorrect selection." << std::endl;
	return menuLevel;
}

MenuLevel ProcessInput(MenuLevel menuLevel, int menuSelect, Player& hero) {
	switch (menuLevel) {
	case front:
		if (menuSelect == 1)
			return battle;
		else if (menuSelect == 2)
			return charpage;
		else if (menuSelect == 3)
			return healer;
		else if (menuSelect < 0)
			return quit;
		else
			return BadSelect(menuLevel);
		break;

	case battle:
		if (menuSelect == 1)
			return inbattle;
		else if (menuSelect < 0)
			return front;
		else
			return BadSelect(menuLevel);
		break;

	case charpage:
		if (menuSelect == 1)
			return equipitem;
		else if (menuSelect == 2) {
			hero.UnEquipWpn();
			return charpage;
		}
		else if (menuSelect == 3) {
			hero.UnEquipArmor();
			return charpage;
		}
		else if (menuSelect == 4)
			return dropitem;
		else if (menuSelect < 0)
			return front;
		else
			return BadSelect(menuLevel);
		break;

	case equipitem:
		if (menuSelect == 1) {
			hero.EquipItem(menuSelect - 1);
			return charpage;
		}
		else if (menuSelect == 2) {
			hero.EquipItem(menuSelect - 1);
			return charpage;
		}
		else if (menuSelect == 3) {
			hero.EquipItem(menuSelect - 1);
			return charpage;
		}
		else if (menuSelect == 4) {
			hero.EquipItem(menuSelect - 1);
			return charpage;
		}
		else if (menuSelect == 5) {
			hero.EquipItem(menuSelect - 1);
			return charpage;
		}
		else if (menuSelect < 0)
			return charpage;
		else
			return BadSelect(menuLevel);
		break;

	case unequipwpn:
		if (menuSelect == 1) {
			hero.UnEquipWpn();
			return charpage;
		}
		else if (menuSelect < 0)
			return charpage;
		else
			return BadSelect(menuLevel);
		break;

	case unequiparmor:
		if (menuSelect == 1) {
			hero.UnEquipArmor();
			return charpage;
		}
		else if (menuSelect < 0)
			return charpage;
		else
			return BadSelect(menuLevel);
		break;

	case dropitem:
		if (menuSelect == 1) {
			hero.DropItem(menuSelect - 1);
			return charpage;
		}
		else if (menuSelect == 2) {
			hero.DropItem(menuSelect - 1);
			return charpage;
		}
		else if (menuSelect == 3) {
			hero.DropItem(menuSelect - 1);
			return charpage;
		}
		else if (menuSelect == 4) {
			hero.DropItem(menuSelect - 1);
			return charpage;
		}
		else if (menuSelect == 5) {
			hero.DropItem(menuSelect - 1);
			return charpage;
		}
		else if (menuSelect < 0)
			return charpage;
		else
			return BadSelect(menuLevel);
		break;

	case healer:
		if (menuSelect < 0)
			return front;
		else
			return BadSelect(menuLevel);
		break;

	default:
		if (menuSelect == 1)
			return front;
		else
			return BadSelect(menuLevel);
		break;
	}
	return front;
}

void FrontMenuOutput() {
	std::cout << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout << "== MAIN MENU ==" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "(1) Battle a Monster" << std::endl;
	std::cout << "(2) View Character Page" << std::endl;
	std::cout << "(3) Visit the Healer" << std::endl;
	std::cout << std::endl;
	std::cout << "(q) Quit the Program" << std::endl;
}

void BattleMenuOutput() {
	std::cout << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout << "== BATTLE MENU ==" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "(1) Enter a battle" << std::endl;
	std::cout << std::endl;
	std::cout << "(q) Return to Previous Menu" << std::endl;
}

void CharPageMenuOutput(Player& hero) {
	std::cout << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout << "== CHARACTER PAGE ==" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "Health: " << hero.GetLife() << "/" << hero.GetMaxLife() << std::endl;
	std::cout << std::endl;
	std::cout << "Equipped:" << std::endl;
	std::cout << " Weapon: " << hero.GetCurWpn().GetItemNameStr() << " (+" << hero.GetCurWpn().GetItemDamage() << ")";
	std::cout << " : Damage: ";
	if (!hero.GetCurWpn().GetIsItem())
		std::cout << "0";
	else
		std::cout << "1";
	std::cout << " to " << hero.GetPlayerDamage() << std::endl;
	std::cout << " Armor: " << hero.GetCurArmor().GetItemNameStr() << " (+" << hero.GetCurArmor().GetItemArmorClass() << ")";
	std::cout << " : Damage Reduced By: 0 to " << hero.GetPlayerArmorClass() << std::endl;
	std::cout << std::endl;
	std::cout << "Inventory:" << std::endl;

	for (int ii = 0; ii < NUMOFINVSLOTS; ii++) {
		std::cout << " Slot " << ii + 1 << ": " << hero.GetCurInv(ii).GetItemNameStr() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "(1) Equip an Item" << std::endl;
	std::cout << "(2) Unequip your Weapon" << std::endl;
	std::cout << "(3) Unequip your Armor" << std::endl;
	std::cout << "(4) Drop an Item" << std::endl;
	std::cout << std::endl;
	std::cout << "(q) Return to Previous Menu" << std::endl;
}

void EquipItemMenuOutput(Player& hero) {
	std::cout << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout << "== ITEM EQUIP ==" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	for (int ii = 0; ii < NUMOFINVSLOTS; ii++) {
		std::cout << "(" << ii + 1 << ") Equip " << hero.GetCurInv(ii).GetItemNameStr() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "(q) Return to Previous Menu" << std::endl;

}

void DropItemMenuOutput(Player& hero) {
	std::cout << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout << "== ITEM DROP ==" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	for (int ii = 0; ii < NUMOFINVSLOTS; ii++) {
		std::cout << "(" << ii + 1 << ") Drop " << hero.GetCurInv(ii).GetItemNameStr() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "(q) Return to Previous Menu" << std::endl;

}

void HealerMenuOutput(Player& hero) {
	std::cout << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout << "== VARTOK THE HEALER ==" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "(The healer casts a magic spell)" << std::endl;

	hero.SetLife(hero.GetMaxLife());

	std::cout << "Your health has returned!" << std::endl;
	std::cout << std::endl;
	std::cout << "(q) Return to Previous Menu" << std::endl;
}

void BadMenuOutput() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << std::endl;
	std::cout << "default menu text. type 1 to return to the main menu. this shouldn't happen!" << std::endl;
}

ItemObj ItemDropped() {
	ItemObj itemDropped;

	ItemObj itemTestArray[NUMOFITEMS];

	for (int ii = 0; ii < NUMOFITEMS; ii++) {
		itemTestArray[ii].SetItem(static_cast<ItemName>(ii));
	}

	int highestItemTest = -1;
	for (int ii = 0; ii < NUMOFITEMS; ii++) {
		if (itemTestArray[ii].GetItemTest() > highestItemTest) {
			highestItemTest = itemTestArray[ii].GetItemTest();
			itemDropped.SetItem(itemTestArray[ii].GetItemName());
		}
	}

	return itemDropped;
}

void BattleMonster(Player& hero) {
	// create monster
	Monster monst;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	if (hero.GetLife() <= 0) {
		std::cout << std::endl;
		std::cout << "You are not healthy enough to fight at the moment. Visit the healer." << std::endl;
		return;
	}
	else {
		while (true) {
			std::string pressEnter;

			std::cout << std::endl;
			std::cout << "You: " << hero.GetLife() << "/" << hero.GetMaxLife() << " " << "Monster: " << monst.GetLife() << "/" << monst.GetMaxLife() << std::endl; // Print life
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			std::cout << "PRESS ENTER TO ATTACK" << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			getline(std::cin, pressEnter);

			pAttack(hero, monst);

			if (monst.GetLife() <= 0) {
				std::cout << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				std::cout << "You have won the battle!" << std::endl;
				int slot = hero.GetFirstEmptyInvSlot(); // set 'slot' to the number of the first empty inv slot, -1 if no empty slots
				ItemObj droppedItem = ItemDropped(); // set 'droppedItem' to a randomly selected item
				if (slot >= 0 && droppedItem.GetIsItem()) { // check if there is indeed an empty slot, GetFirstEmptyInvSlot() returns -1 if there are no empty slots
					hero.SetCurInv(slot, droppedItem); // put dropped item in empty slot
					std::cout << "You have acquired an item: " << droppedItem.GetItemNameStr() << std::endl;
					std::cout << "You put it in inventory slot " << slot + 1 << std::endl;
				}
				else if (!droppedItem.GetIsItem()) {
					std::cout << "The monster didn't drop anything." << std::endl;
				}
				else if (slot < 0) {
					std::cout << "Not enough room in your inventory, discarding item: " << droppedItem.GetItemNameStr() << std::endl;
				}
				else {
					std::cout << "this shouldn't happen!" << std::endl;
				}
				std::cout << std::endl;
				std::cout << "Press enter to claim victory." << std::endl;
				getline(std::cin, pressEnter);
				return;
			}
			else {
				mAttack(hero, monst);
			}

			if (hero.GetLife() <= 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				std::cout << std::endl;
				std::cout << "You have lost the battle." << std::endl;
				std::cout << std::endl;
				std::cout << "Press enter to admit defeat." << std::endl;
				getline(std::cin, pressEnter);
				return;
			}
		}
	}
}

int main() {

	// initialize random number generator with current time
	srand((unsigned int)time(0));

	/*
	int k;
	for (k = 0; k < 255; k++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
		std::cout << k << "this is a test!" << std::endl;
	}

	std::cin.get();
	return 0;
	*/

	// declare and initialize variables
	int menuSelect = 0;
	MenuLevel menuLevel = front; // start at main menu

	// create hero object
	Player hero;

	do {

		// display menu text
		switch (menuLevel) {
		case front:
			FrontMenuOutput();
			break;
		case charpage:
			CharPageMenuOutput(hero);
			break;
		case equipitem:
			EquipItemMenuOutput(hero);
			break;
		case dropitem:
			DropItemMenuOutput(hero);
			break;
		case healer:
			HealerMenuOutput(hero);
			break;
		case battle:
			BattleMenuOutput();
			break;
		case inbattle:
			BattleMonster(hero);
			menuLevel = battle;
			continue;
			break;
		default:
			BadMenuOutput();
			break;
		}

		menuSelect = GetInput();

		menuLevel = ProcessInput(menuLevel, menuSelect, hero);

	} while (menuLevel != quit);

	return 0;

}

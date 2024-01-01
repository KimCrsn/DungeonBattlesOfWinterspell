#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "GameText.h"
#include "IWeapon.h"
#include "ICreature.h"

class UI
{
private:
	GameText gameText;

public:
	void DisplayMap(std::vector<std::string> dungeonRooms, int indexStop);
	void DescribeDungeonRoom(std::string description);
	void DisplayTurnOrder(std::vector<std::string> creatureNames, std::string dungeonRoomName);
	void PlayerAttack(IWeapon* weapon, std::vector<std::shared_ptr<ICreature>> turnOrder);
	void EnemyTurn();
};


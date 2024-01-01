#include "UI.h"
#include "DungeonRoom.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <map>

void UI::DisplayMap(std::vector<std::string> dungeonRooms, int indexStop) {
    gameText.WriteLine("You have made a discovery! Your next dungeon location is revealed before you...\n\n");

    //for (int i = 0; i < dungeonRooms.size(); i++) {
    //    if (i == 4 || i == 8) {
    //        std::cout << "\n\n";
    //    }
    //    if (i != 0 && i >= indexStop) {
    //        if (i != dungeonRooms.size() - 1) {
    //            gameText.WriteText("Undiscovered...    -->  ");
    //        } else {
    //            gameText.WriteText("Undiscovered");
    //        }
    //    }
    //    else {
    //        if (i != dungeonRooms.size() - 1) {
    //            gameText.WriteText(dungeonRooms[i] + "   -->  ");
    //        }
    //        else {
    //            gameText.WriteText(dungeonRooms[i]);
    //        }
    //    }
    //}

    _getch();
    system("cls");
};

void UI::DescribeDungeonRoom(std::string description) {
    gameText.WriteLine(description);
    _getch();
    return;
}

void UI::DisplayTurnOrder(std::vector<std::string> creatureNames, std::string dungeonRoomName) {
    system("cls");
    gameText.WriteLine(dungeonRoomName + "\n\n");
    for (std::string name : creatureNames) {
        gameText.WriteLine(name);
    }
    _getch();
    return;
}

void UI::PlayerAttack(IWeapon* weapon, std::vector<std::shared_ptr<ICreature>> turnOrder){
    bool skillChosen = false; /**/ int falseSelectionCounter = 0; /**/ int attackPoints = 0;

    while (!skillChosen) {
    gameText.WriteLine("\nIt's time to fight! Choose your skill!");
    gameText.WriteLine("1)  " + weapon->GetPrimarySkillName());
    gameText.WriteLine("2)  " + weapon->GetSecondarySkillName() + "\n");
    std::string skillSelection; std::cin >> skillSelection;

    // player chooses between the two skills of their weapon/class
        if (skillSelection == "1") {
            bool skillChosen = true; /**/ attackPoints = weapon->UseSkillPrimary();
            system("cls");
        }
        else if (skillSelection == "2") {
            bool skillChosen = true; /**/ attackPoints = weapon->UseSkillSecondary();
            system("cls");
        }
        else {
            falseSelectionCounter++;
                if (falseSelectionCounter > 1) {
                    // do nothing so we don't get more than one of the error messages
                }
                else {
                    gameText.WriteLine("Please select one of your powers!");
                }
        }
       
        gameText.WriteLine("Who is the lucky foe?");
        // map to store string (int) | enemy so we can track for output and taking in user input dynamically and more simply
        std::map<std::string, std::shared_ptr<ICreature>> enemySelectionTracker; /**/ int enemyCounter = 1; // map of user's count/selection paired with the enemy associated

        // outputs each enemy into list with a counter
        for (std::shared_ptr<ICreature> creature : turnOrder) {
            if (std::shared_ptr<IEnemy> enemy = std::dynamic_pointer_cast<IEnemy>(creature)) {
                enemySelectionTracker[std::to_string(enemyCounter)] = enemy;
                enemyCounter++;
            }
        }
        for (const auto& pair : enemySelectionTracker) {
            if (std::shared_ptr<IEnemy> enemy = std::dynamic_pointer_cast<IEnemy>(pair.second)) {
                gameText.WriteLine(pair.first + ")     " + enemy->GetName());
            }
        }
        /*for (const auto& pair : enemySelectionTracker) {
            gameText.WriteLine(pair.first + ")     " + pair.second->GetName());
            std::cout << pair.first; std::cout << pair.second;
            std::cout << "attempt";
        }*/

        std::string enemySelect; std::cin >> enemySelect;
        auto it = enemySelectionTracker.find(enemySelect); // find user input in the map of string/int to name of enemy book by selection of string/int
        if (it != enemySelectionTracker.end()) {
            if (std::shared_ptr<IEnemy> enemy = std::dynamic_pointer_cast<IEnemy>(enemySelectionTracker[enemySelect])) {
                gameText.WriteLine("You have chosen to attack " + enemy->GetName());
                enemy->TakeDamage(attackPoints); /* check if enemy is dead after attack */ if (enemy->GetIsDead()) { std::cout << "enemy has died"; }
            }
        }
        else {

        }
    }
}

void EnemyTurn();
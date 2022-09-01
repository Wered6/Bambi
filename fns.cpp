#include <iostream>
#include <stdlib.h>
#include "fns.hpp"
#include <vector>


//story

void intro() {

    std::cout << "===============\n";
    std::cout << "BAMBI'S CASTLE!\n";
    std::cout << "===============\n\n";

}

void story1(std::string name) {

    std::cout << "\nHello " << name << "!\nWe called you to help us defeat the three-headed dog Bambi! She is very dangerous monster and she is a threat to our village!\n";

    next();

}

void story2(std::string name) {

    std::cout << "\n\n" << name << " To get to the castle you have to take a long trip through woods and mountains. During the adventure we will collect various artifacts to strengthen ourselves!\n";

    next();

}



void next() {

    std::string go;

    std::cout << "\nType anything and click 'Enter' to go further.\n";
    std::cin >> go;

}

int cube6() {

    srand (time(NULL));
 
    return rand() % 6 + 1;

}


void stats_details() {

    std::string ready;
    int stat;


    std::cout <<"\nDo you need more information about any of statistics?\n";

    while (ready != "Y" && ready != "N" && ready != "y" && ready != "n") {
    std::cout << "(Y/N)?\n";
    std::cin >> ready;
    }

    if (ready == "Y" || ready == "y") {

    std::cout << "\nEnter stat number to show descritpion (or '0' to go ahead):\n";


    while (!(std::cin >> stat)) {

        std::cout << "\n\nEnter valid stat number!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');

    }

        while (stat != 0) {
            
            if (stat == 1) {
                std::cout << "\n\n[HP] is your health points.";
            }
            else if (stat == 2) {
                std::cout << "\n\n[Mana] is kind of energy you have in yourself. It is required to cast spells or use some magical artifacts!";
            }
            else if (stat == 3) {
                std::cout << "\n\n[Strength] shows how much strength you have. It increases damage from non-magical weapons.";
            }
            else if (stat == 4) {
                std::cout << "\n\n[Intellect] shows how wise you are. It increases damage from magical weapons or spells.";
            }
            else if (stat == 5) {
                std::cout << "\n\n[Luck] is most random statistic you have. It increases loot chance and critical damage chance.";
            }
            else {
                std::cout << "\n\nEnter valid stat number!";
            }
            std::cout << "\n\nEnter stat number to show descritpion (or '0' to go ahead):\n";


            while (!(std::cin >> stat)) {
                std::cout << "\n\nEnter valid stat number!\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');

            }

        }

    }

}



void battle(Creature &name1, Creature &name2) {

    int choose;

    std::cout << "\nWhat you want to do?\n";
    std::cout << "1. Use main hand to attack.\n";
    std::cout << "2. Cast a spell.\n";
    std::cout << "3. Search bag for artifacts.\n";
    std::cout << "Choose:\n";

    while (!(std::cin >> choose)) {

        std::cout << "\n\nEnter valid number!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');

    }

    while (!((name1.get_hp() <= 0) || (name2.get_hp() <=0))) {

        if (choose == 1) {

            int dmg = cube6() * name1.get_strength();
            name2.sub_hp(dmg);
            if (name2.get_hp() < 0) {
                name2.set_hp(0);
            }
            std::cout << "\nYou dealt " << dmg << " dmg to " << name2.get_nickname() << "!\n";
            name1.show_stats();
            name2.show_stats();

        } 

        else if (choose == 2) {

            name2.sub_hp(cube6() * name1.get_intellect());
        
        }

        else if (choose == 3) {

            std::cout << "You don't have any artifacts.\n";
    
        }
        else {

            std::cout << "\n\nEnter valid number!\n";
            
        }

        while (!((name1.get_hp() <= 0) || (name2.get_hp() <=0))) {

            std::cout << "\nWhat you want to do?\n";
            std::cout << "1. Use main hand to attack.\n";
            std::cout << "2. Cast a spell.\n";
            std::cout << "3. Search bag for artifacts.\n";
            std::cout << "Choose:\n";
            break;
        }

        while (!((name1.get_hp() <= 0) || (name2.get_hp() <=0)) && !(std::cin >> choose)) {

            std::cout << "\n\nEnter valid number!\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');

        }

    }

}


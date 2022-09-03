#include <iostream>
#include <stdlib.h>
#include "fns.hpp"
#include "windows.h"
#include <string>


//story

void delay_text(std::string text, int time) {
    for (char i : text) {
        std::cout << i;
        Sleep(time);
    }
}
void cin_only_numbers(int &input, int end, int start) {
    while (!(std::cin >> input) || input < start || input > end) {
        delay_text("\nEnter valid number!\n");
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        }
}

void intro() {
    delay_text("===============\n");
    delay_text("BAMBI'S CASTLE!\n");
    delay_text("===============\n\n");
}
void story1(std::string name) {
    delay_text("\nHello " + name + "!\nWe called you to help us defeat the three-headed dog Bambi! She is very dangerous monster and she is a threat to our village!\n");

    next();
}
void story2(std::string name) {
    delay_text("\n\n" + name + " To get to the castle you have to take a long trip through woods and mountains. During the adventure we will collect various artifacts to strengthen ourselves!\n");

    next();
}


void next() {
    std::string go;
    delay_text("\nType anything and click 'Enter' to go further.\n");
    std::cin >> go;
}
int cube(int i) {
    srand (time(NULL));
    return rand() % i + 1;
}
int cube2() {
    srand (time(NULL));
    return rand() % 2 + 1;
}
int cube6() {
    srand (time(NULL));
    return rand() % 6 + 1;
}



void stats_details() {
    std::string ready;
    int stat;


    delay_text("\nDo you need more information about any of statistics?\n");

    while (ready != "Y" && ready != "N" && ready != "y" && ready != "n") {
    delay_text("(Y/N)?\n");
    std::cin >> ready;
    }

    if (ready == "Y" || ready == "y") {
    delay_text("\nEnter stat number to show descritpion (or '0' to go ahead):\n");

    while (!(std::cin >> stat)) {
        delay_text("\n\nEnter valid stat number!\n");
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

        while (stat != 0) {
            
            if (stat == 1) {
                delay_text("\n\n[HP] is your health points.");
            }
            else if (stat == 2) {
                delay_text("\n\n[Mana] is kind of energy you have in yourself. It is required to cast spells or use some magical artifacts!");
            }
            else if (stat == 3) {
                delay_text("\n\n[Strength] shows how much strength you have. It increases damage from non-magical weapons.");
            }
            else if (stat == 4) {
                delay_text("\n\n[Intellect] shows how wise you are. It increases damage from magical weapons or spells.");
            }
            else if (stat == 5) {
                delay_text("\n\n[Luck] is most random statistic you have. It increases loot chance and critical damage chance.");
            }
            else {
                delay_text("\n\nEnter valid stat number!");
            }
            delay_text("\n\nEnter stat number to show descritpion (or '0' to go ahead):\n");


            while (!(std::cin >> stat)) {
                delay_text("\n\nEnter valid stat number!\n");
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
    }
}

void hand_dmg(Creature &op1, Creature &op2) {
    int dmg = cube6() * op1.get_strength();
    op2.sub_hp(dmg);
    if (op2.get_hp() < 0) {
        op2.set_hp(0);
    }
    delay_text("\n" + op1.get_nickname() + " used bare hands and dealt ");
    std::cout << dmg;
    delay_text(" physical dmg to " + op2.get_nickname() + "!\n");
}
void weapon_dmg(Creature &op1, Creature &op2, Weapon weapon) {
    int dmg = cube6() * op1.get_strength() * weapon.get_base_dmg();
    op2.sub_hp(dmg);
    if (op2.get_hp() < 0) {
        op2.set_hp(0);
    }
    delay_text("\n" + op1.get_nickname() + " used " + weapon.get_name() + " and dealt ");
    std::cout << dmg;
    delay_text(" physical dmg to " + op2.get_nickname() + "!\n");
}
void spell_dmg(Creature &op1, Creature &op2, Spell spell) {
    int dmg = cube6() * op1.get_intellect() * spell.get_base_dmg();
    int mana_cost = spell.get_mana_cost();
    if (op1.get_mana() < mana_cost) {
        delay_text("You do not have enough mana to cast this spell!");
    } else {
        op1.sub_mana(mana_cost);
        op2.sub_hp(dmg);
        delay_text("\n" + op1.get_nickname() + " used " + spell.get_name() + " and dealt ");
        std::cout << dmg;
        delay_text(" magical dmg to " + op2.get_nickname() + "!\n");
    }
    if (op2.get_hp() < 0) {
        op2.set_hp(0);
    }
}

void change_opponent(int &opponent) {
    if (opponent == 1) {
        opponent = 2;
    } else {
        opponent = 1;
    }
}

void battle(Creature &hero, Creature &enemy) {
    int choose;
    int opponent = 1;
    while ((hero.get_hp() > 0) && (enemy.get_hp() > 0)) {
        if (opponent == 1) {
            delay_text("\nWhat you want to do?\n");
            delay_text("1. Use hand to attack.\n");
            delay_text("2. Use weapon to attack.\n");
            delay_text("3. Cast a spell.\n");
            delay_text("Choose:\n");

            cin_only_numbers(choose, 3);
            if (choose == 1) {
                hand_dmg(hero, enemy);
                hero.show_stats();
                enemy.show_stats();
            } else if (choose == 2) {
                delay_text("You can't use weapons now!\n");
            } else if (choose == 3) {
                int choose_spell;
                delay_text("Choose what spell you want to use:\n\n");
                hero.show_spells();
                cin_only_numbers(choose_spell, hero.get_spells().size());
                spell_dmg(hero, enemy, hero.get_spells()[choose_spell - 1]);
                hero.show_stats();
                enemy.show_stats();
            }
        } else {
            spell_dmg(enemy, hero, enemy.get_spells()[cube(enemy.get_spells().size()) - 1]);
            hero.show_stats();
            enemy.show_stats();
        }
        change_opponent(opponent);
        if (hero.get_hp() == 0) {
            hero.death();
        } else if (enemy.get_hp() == 0) {
            enemy.death();
        }
    }
}
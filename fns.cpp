#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include "fns.hpp"




void change_color(int i) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,i);
}
void back_to_default_color() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,7);
}
void delay_text(std::string text, int time) {
    back_to_default_color();
    for (char i : text) {
        std::cout << i;
        Sleep(time);
    }
}

void cin_only_numbers(int &input, int end, int start) {
    change_color();
    while (!(std::cin >> input) || input < start || input > end) {
        delay_text("\nEnter valid number!\n");
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        change_color();
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
    delay_text("\n\n" + name + " to get to the castle you have to take a long trip through woods and mountains. During the adventure we will collect various artifacts to strengthen ourselves!\n");

    next();
}


void next() {
    std::string go;
    delay_text("\nType anything and click 'Enter' to go further.\n");
    change_color();
    std::cin >> go;
}
int cube(int i, int j) {
    srand (time(NULL));
    return rand() % i + j;
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
    change_color();
    std::cin >> ready;
    }

    if (ready == "Y" || ready == "y") {
    
        
        while (stat != 0) {
            delay_text("\nEnter stat number to show descritpion (or '0' to go ahead):\n");
            cin_only_numbers(stat, 5, 0);
            if (stat == 1) {
                delay_text("\n[HP] is your health points.\n");
            }
            else if (stat == 2) {
                delay_text("\n[Mana] is kind of energy you have in yourself. It is required to cast spells or use some magical artifacts!\n");
            }
            else if (stat == 3) {
                delay_text("\n[Strength] shows how much strength you have. It increases damage from non-magical weapons.\n");
            }
            else if (stat == 4) {
                delay_text("\n[Intellect] shows how wise you are. It increases damage from magical weapons or spells.\n");
            }
            else if (stat == 5) {
                delay_text("\n[Luck] increases loot chance and critical damage chance.\n");
            }
            delay_text("\n"); //i dont know why the fuck this has to be here, without it "while" doesnt work!
        }
    }
}


void change_opponent(int &op) {
    if (op == 1) {
        op = 2;
    } else {
        op = 1;
    }
}

void battle(Creature &hero, Creature &enemy) {
    int choose;
    int op_num = 1;
    delay_text("Fight between " + hero.get_nickname() + " and " + enemy.get_nickname() + " begins!\n");
    hero.show_stats();
    enemy.show_stats();
    while ((hero.get_hp() > 0) && (enemy.get_hp() > 0)) {
        if (op_num == 1) {
            delay_text("\nWhat you want to do?\n");
            delay_text("1. Use hand to attack.\n");
            delay_text("2. Use weapon to attack.\n");
            delay_text("3. Cast a spell.\n");
            delay_text("Choose:\n");

            cin_only_numbers(choose, 3);
            switch (choose) {
                case 1:
                    hero.hand_dmg(enemy);
                    hero.show_stats();
                    enemy.show_stats();
                    change_opponent(op_num);
                    break;
                case 2:
                    int choose_weapon;
                    delay_text("Choose what weapon you want to use:\n\n");
                    hero.show_weapons();
                    cin_only_numbers(choose_weapon, hero.get_weapons().size());
                    hero.weapon_dmg(enemy, hero.get_weapons()[choose_weapon - 1]);
                    hero.show_stats();
                    enemy.show_stats();
                    change_opponent(op_num);
                    break;
                case 3:
                    int choose_spell;
                    delay_text("Choose what spell you want to use:\n\n");
                    hero.show_spells();
                    cin_only_numbers(choose_spell, hero.get_spells().size());
                    if (hero.get_spells()[choose_spell - 1].get_mana_cost() <= hero.get_mana()) {
                        hero.spell_dmg(enemy, hero.get_spells()[choose_spell - 1]);
                        hero.show_stats();
                        enemy.show_stats();
                        change_opponent(op_num);
                    } else {
                        delay_text("You do not have enough mana to cast this spell. Choose another.\n");
                    }
                    break;
            }
        } else {
            int i = cube(3);
            if (i == 1 && enemy.get_spells().size() != 0) {
                enemy.spell_dmg(hero, enemy.get_spells()[cube(enemy.get_spells().size()) - 1]);
            } else {
                enemy.weapon_dmg(hero, enemy.get_weapons()[cube(enemy.get_weapons().size()) -1]);
            }
            hero.show_stats();
            enemy.show_stats();
            change_opponent(op_num);
        }
        if (hero.get_hp() == 0) {
            hero.death();
        } else if (enemy.get_hp() == 0) {
            enemy.death();
        }
    }
}
int critical_chance(int luck) {
    int r_num = cube(100, 1);
    if (r_num <= luck) {
        delay_text("\nCRITICAL!");
        return 2;
    } else {
        return 1;
    }
}
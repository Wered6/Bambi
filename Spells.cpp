#include <iostream>
#include "fns.hpp"



Spell::Spell(std::string new_name, int new_base_dmg, int new_mana_cost) {
    name = new_name;
    base_dmg = new_base_dmg;
    mana_cost = new_mana_cost;
}
Spell::~Spell() {

}

void Spell::show_stats() {
    delay_text("\n" + name + " spell stats:\n\n");
    delay_text("[Base DMG]:      ");
    std::cout << base_dmg << "\n";
    delay_text("[Mana cost]:     ");
    std::cout << mana_cost << "\n"; 
}

std::string Spell::get_name() {
    return name;
}
int Spell::get_base_dmg() {
    return base_dmg;
}
int Spell::get_mana_cost() {
    return mana_cost;
}
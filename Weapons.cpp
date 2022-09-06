#include <iostream>
#include "fns.hpp"



Weapon::Weapon(string new_name, int new_base_dmg, int new_critical_chance) {
    name = new_name;
    base_dmg = new_base_dmg;
    critical_chance = new_critical_chance;
}
Weapon::~Weapon() {

}

void Weapon::show_stats() {
    delay_text("\n" + name + " weapon stats:\n\n");
    delay_text("[Base DMG]:      ");
    cout << base_dmg << "\n";
    delay_text("[Crit Chance]:   ");
    cout << critical_chance << "\n";
}

string Weapon::get_name() {
    return name;
}
int Weapon::get_base_dmg() {
    return base_dmg;
}
int Weapon::get_critical_chance() {
    return critical_chance;
}
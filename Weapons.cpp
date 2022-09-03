#include <iostream>
#include "fns.hpp"



Weapon::Weapon(std::string new_name, int new_base_dmg) {
    name = new_name;
    base_dmg = new_base_dmg;
}
Weapon::~Weapon() {

}

void Weapon::show_stats() {
    delay_text("\n" + name + " weapon stats:\n\n");
    delay_text("[Base DMG]:      ");
    std::cout << base_dmg << "\n";
}

std::string Weapon::get_name() {
    return name;
}
int Weapon::get_base_dmg() {
    return base_dmg;
}
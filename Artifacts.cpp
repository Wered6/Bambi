#include <iostream>
#include "fns.hpp"



Artifact::Artifact(string new_name, int new_hp, int new_mana, int new_strength, int new_intellect, int new_luck) {
    name = new_name;
    hp = new_hp;
    mana = new_mana;
    strength = new_strength;
    intellect = new_intellect;
    luck = new_luck;
}
Artifact::~Artifact() {
 
}

void Artifact::show_stats() {
    cout << "\n\n" << name << " artifact stats:\n\n";
    cout << "[HP]:        +" << hp << "\n";
    cout << "[Mana]:      +" << mana << "\n";
    cout << "[Strength]:  +" << strength << "\n";
    cout << "[Intellect]: +" << intellect << "\n";
    cout << "[Luck]:      +" << luck << "\n";
}

string Artifact::get_name() {
    return name;
}
int Artifact::get_hp() {
    return hp;
}
int Artifact::get_mana() {
    return mana;
}
int Artifact::get_strength() {
    return strength;
}
int Artifact::get_intellect() {
    return intellect;
}
int Artifact::get_luck() {
    return luck;
}

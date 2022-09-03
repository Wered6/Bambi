#include <iostream>
#include <windows.h>
#include "fns.hpp"



Creature::Creature(std::string new_nickname, int new_hp, int new_mana, int new_strength, int new_intellect, int new_luck) {
    nickname = new_nickname;
    hp = new_hp;
    mana = new_mana;
    strength = new_strength;
    intellect = new_intellect;
    luck = new_luck;
}
Creature::~Creature() {

}

void Creature::death() {
    std::cout << "\n" << nickname << " died! R.I.P.! Goodbye Drama!\n";
}

void Creature::show_stats() {
    delay_text("\n\n" + nickname + " stats:\n\n");
    delay_text("1) [HP]:        ");
    std::cout << hp << "\n";
    delay_text("2) [Mana]:      ");
    std::cout << mana << "\n";
    delay_text("3) [Strength]:  ");
    std::cout << strength << "\n";
    delay_text("4) [Intellect]: ");
    std::cout << intellect << "\n";
    delay_text("5) [Luck]:      ");
    std::cout << luck << "\n";
}



void Creature::set_nickname() {
    delay_text("Enter your name adventurer:\n");
    change_color();
    std::cin >> nickname;
}
std::string Creature::get_nickname() {
    return nickname;
}


void Creature::set_hp(int new_hp) {
    hp = new_hp;
}
void Creature::add_hp(int added_hp) {
    hp += added_hp;
}
void Creature::sub_hp(int subbed_hp) {
    hp -= subbed_hp;
}
int Creature::get_hp() {
    return hp;
}

void Creature::set_mana(int new_mana) {
    mana = new_mana;
}
void Creature::add_mana(int added_mana) {
    mana += added_mana;
}
void Creature::sub_mana(int subbed_mana) {
    mana -= subbed_mana;
}
int Creature::get_mana() {
    return mana;
}

void Creature::set_strength(int new_strength) {
    strength = new_strength;
}
void Creature::add_strength(int added_strength) {
    strength += added_strength;
}
void Creature::sub_strength(int subbed_strength) {
    strength -= subbed_strength;
}
int Creature::get_strength() {
    return strength;
}

void Creature::set_intellect(int new_intellect) {
    intellect = new_intellect;
}
void Creature::add_intellect(int added_intellect) {
    intellect += added_intellect;
}
void Creature::sub_intellect(int subbed_intellect) {
    intellect -= subbed_intellect;
}
int Creature::get_intellect() {
    return intellect;
}

void Creature::set_luck(int new_luck) {
    luck = new_luck;
}
void Creature::add_luck(int added_luck) {
    luck += added_luck;
}
void Creature::sub_luck(int subbed_luck) {
    luck -= subbed_luck;
}
int Creature::get_luck() {
    return luck;
}


void Creature::add_spell(Spell new_spell) {
    spells.push_back(new_spell);
}
std::vector<Spell> Creature::get_spells() {
    return spells;
}
void Creature::show_spells() {
    int i = 1;
    for (Spell spell : get_spells()) {
        std::cout << "\n" << i;
        i++;
        spell.show_stats();
    }
}

void Creature::add_weapon(Weapon new_weapon) {
    weapons.push_back(new_weapon);
}
std::vector<Weapon> Creature::get_weapons() {
    return weapons;
}
void Creature::show_weapons() {
    int i = 1;
    for (Weapon weapon : get_weapons()) {
        std::cout << "\n" << i;
        i++;
        weapon.show_stats();
    }
}
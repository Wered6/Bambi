#include <iostream>
#include "fns.hpp"



Creature::Creature(std::string new_nickname, int new_hp, int new_mana, int new_strength, int new_intellect, int new_luck) {

    nickname = new_nickname;
    hp = new_hp;
    mana = new_mana;
    strength = new_strength;
    intellect = new_intellect;
    luck = new_luck;

}

void Creature::death() {

    std::cout << nickname << " died! R.I.P.! Goodbye Drama!\n";

}

void Creature::show_stats() {

    std::cout << "\n\n" << nickname << " stats:\n\n";
    std::cout << "1) [HP]:        " << hp << "\n";
    std::cout << "2) [Mana]:      " << mana << "\n";
    std::cout << "3) [Strength]:  " << strength << "\n";
    std::cout << "4) [Intellect]: " << intellect << "\n";
    std::cout << "5) [Luck]:      " << luck << "\n";

}



void Creature::set_nickname() {

    std::cout << "Enter your name adventurer:\n";
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
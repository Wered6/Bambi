#include <iostream>
#include "fns.hpp"



Creature::Creature(string new_name, int new_hp, int new_mana, int new_strength, int new_intellect, int new_luck) {
    name = new_name;
    hp = new_hp;
    mana = new_mana;
    strength = new_strength;
    intellect = new_intellect;
    luck = new_luck;
}
Creature::~Creature() {

}

void Creature::death() {
    delay_text("\n" + name + " died! R.I.P.! Goodbye Drama!\n");
}


void Creature::show_stats() {
    delay_text("\n\n" + name + " stats:\n\n");
    delay_text("1) [HP]:        ");
    cout << hp << "\n";
    delay_text("2) [Mana]:      ");
    cout << mana << "\n";
    delay_text("3) [Strength]:  ");
    cout << strength << "\n";
    delay_text("4) [Intellect]: ");
    cout << intellect << "\n";
    delay_text("5) [Luck]:      ");
    cout << luck << "\n";
}



void Creature::set_name() {
    delay_text("Enter your name adventurer:\n");
    change_color();
    getline(cin, name);
}
string Creature::get_name() {
    return name;
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
vector<Spell> Creature::get_spells() {
    return spells;
}
void Creature::show_spells() {
    int i = 1;
    for (Spell spell : get_spells()) {
        cout << "\n" << i;
        i++;
        spell.show_stats();
    }
}

void Creature::add_weapon(Weapon new_weapon) {
    weapons.push_back(new_weapon);
}
vector<Weapon> Creature::get_weapons() {
    return weapons;
}
void Creature::show_weapons() {
    int i = 1;
    for (Weapon weapon : get_weapons()) {
        cout << "\n" << i;
        i++;
        weapon.show_stats();
    }
}

void Creature::hand_dmg(Creature &opponent) {
    int dmg = cube6() * get_strength() * critical_chance(get_luck());
    opponent.sub_hp(dmg);
    if (opponent.get_hp() < 0) {
        opponent.set_hp(0);
    }
    delay_text("\n" + get_name() + " used bare hands and dealt ");
    cout << dmg;
    delay_text(" physical dmg to " + opponent.get_name() + "!\n");
}
void Creature::weapon_dmg(Creature &opponent, Weapon weapon) {
    int dmg = cube6() * get_strength() * weapon.get_base_dmg() * critical_chance(get_luck() + weapon.get_critical_chance());
    opponent.sub_hp(dmg);
    if (opponent.get_hp() < 0) {
        opponent.set_hp(0);
    }
    delay_text("\n" + get_name() + " used " + weapon.get_name() + " and dealt ");
    cout << dmg;
    delay_text(" physical dmg to " + opponent.get_name() + "!\n");
}
void Creature::spell_dmg(Creature &opponent, Spell spell) {
    int dmg = cube6() * get_intellect() * spell.get_base_dmg() * critical_chance(get_luck());
    int mana_cost = spell.get_mana_cost();
    sub_mana(mana_cost);
    opponent.sub_hp(dmg);
    delay_text("\n" + get_name() + " used " + spell.get_name() + " and dealt ");
    cout << dmg;
    delay_text(" magical dmg to " + opponent.get_name() + "!\n");
    if (opponent.get_hp() < 0) {
        opponent.set_hp(0);
    }
} 


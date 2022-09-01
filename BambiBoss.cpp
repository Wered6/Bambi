#include <iostream>
#include "fns.hpp"

int main() {

    intro();


    Creature Player1("Player1");

    Creature Bambi("Bambi");

    Player1.set_nickname();

    story1(Player1.get_nickname());

    story2(Player1.get_nickname());

    Player1.show_stats();

    stats_details();

    battle(Player1, Bambi);

}
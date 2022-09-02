#include <iostream>
#include "fns.hpp"
#include <vector>


int main() {

    intro();


    Creature Player1("Player1");

    Creature Bambi("Bambi");

    Spell FireBall("FIRE BALL", 8, 10);
    Spell IceBall("ICE BALL", 3, 5);

    Bambi.add_spell(FireBall);
    Bambi.add_spell(IceBall);

    for (Spell spell : Bambi.get_spells()) {

        spell.show_stats();

    }
   

    Player1.set_nickname();

    story1(Player1.get_nickname());

    story2(Player1.get_nickname());

    Player1.show_stats();

    stats_details();

    battle(Player1, Bambi);

}

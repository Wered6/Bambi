#include <iostream>
#include "fns.hpp"


int main() {

    intro();


    Creature Player1("Player1");

    Creature Bambi("Bambi", 200);

    Spell FireBall("FIRE BALL", 6, 10);
    Spell IceBall("ICE BALL", 2, 5);
    Spell FireBlast("FIRE BLAST", 2, 0);
    Spell IceHurricane("ICE HURRICANE", 3, 0);

    Player1.add_spell(FireBall);
    Player1.add_spell(IceBall);


    Bambi.add_spell(FireBlast);
    Bambi.add_spell(IceHurricane);
   

    // Player1.set_nickname();

    // story1(Player1.get_nickname());

    // story2(Player1.get_nickname());

    // Player1.show_stats();

    // stats_details();

    battle(Player1, Bambi);



}

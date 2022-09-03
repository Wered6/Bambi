#include <iostream>
#include "fns.hpp"


int main() {

    intro();

    Creature Player1("Player1");
    Creature Bambi("Bambi", 200);

    Spell FireBall("FIRE BALL", 6, 50);
    Spell IceBall("ICE BALL", 2, 10);
    Spell FireBlast("FIRE BLAST", 2, 0);
    Spell IceHurricane("ICE HURRICANE", 3, 0);
    Weapon Axe("AXE", 3);
    Weapon Sword("SWORD", 2);

    Player1.add_spell(FireBall);
    Player1.add_spell(IceBall);
    Player1.add_weapon(Axe);
    Player1.add_weapon(Sword);

    Bambi.add_spell(FireBlast);
    Bambi.add_spell(IceHurricane);
   

    Player1.set_nickname();

    story1(Player1.get_nickname());

    story2(Player1.get_nickname());

    Player1.show_stats();

    stats_details();

    battle(Player1, Bambi);


}

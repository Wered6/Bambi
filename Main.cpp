#include <iostream>
#include "fns.hpp"


int main() {

    

    Creature Player1("Player1", 100, 100, 5, 5, 5);

    Creature Bambi("Bambi", 200);
    Creature Lady("Lady", 150, 100, 2, 1);

    Spell FireBall("FIRE BALL", 6, 50);
    Spell IceBall("ICE BALL", 2, 10);
    Spell FireBlast("FIRE BLAST", 2, 0);
    Spell IceHurricane("ICE HURRICANE", 3, 0);
    Weapon Axe("AXE", 3);
    Weapon Sword("SWORD", 2, 50);
    Weapon Claws("CLAWS", 2);
    Weapon Bite("BITE", 3);

    Player1.add_spell(FireBall);
    Player1.add_spell(IceBall);
    Player1.add_weapon(Axe);
    Player1.add_weapon(Sword);

    Bambi.add_spell(FireBlast);
    Bambi.add_spell(IceHurricane);
    Bambi.add_weapon(Claws);
    Bambi.add_weapon(Bite);

    Lady.add_spell(FireBlast);
    Lady.add_spell(IceHurricane);
    Lady.add_weapon(Claws);
    Lady.add_weapon(Bite);

    intro();

    Player1.set_nickname();

    story1(Player1.get_nickname());

    story2(Player1.get_nickname());

    Player1.show_stats();

    stats_details();

    battle(Player1, Lady);

    battle(Player1, Bambi);


}

#include <iostream>
#include "fns.hpp"



void Hero::death() {
    delay_text("\n" + name + " died! R.I.P.! Goodbye Drama!\n");
    delay_text("\nGAME OVER");
    exit(0);
}
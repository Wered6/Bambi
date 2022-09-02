#include <vector>

class Spell {

    std::string name;
    int base_dmg;
    int mana_cost;

public:

    Spell(std::string new_name, int new_base_dmg=0, int new_mana_cost=0);
    ~Spell();

    void show_stats();

    std::string get_name();
    int get_base_dmg();
    int get_mana_cost();

};
class Weapon {

    std::string name;
    int base_dmg;

public:

    Weapon(std::string new_name, int new_base_dmg=0);
    ~Weapon();

    void show_stats();

    std::string get_name();
    int get_base_dmg();

};
class Artifact {

    std::string name;
    int hp;
    int mana;
    int strength;
    int intellect;
    int luck;

public:

    Artifact(std::string new_name, int new_hp=0, int new_mana=0, int new_strength=0, int new_intellect=0, int new_luck=0);
    ~Artifact();

    void show_stats();

    std::string get_name();
    int get_hp();
    int get_mana();
    int get_strength();
    int get_intellect();
    int get_luck();

};
class Creature {

    std::string nickname;
    int hp;
    int mana;
    int strength;
    int intellect;
    int luck;

    std::vector<Spell> spells;

public:

    Creature(std::string new_nickname, int new_hp=100, int new_mana=100, int new_strength=5, int new_intellect=5, int new_luck=0);
    ~Creature();

    void death();

    void show_stats();


    void set_nickname();
    std::string get_nickname();


    void set_hp(int new_hp);
    void add_hp(int added_hp);
    void sub_hp(int subbed_hp);
    int get_hp();

    void set_mana(int new_mana);
    void add_mana(int added_mana);
    void sub_mana(int subbed_mana);
    int get_mana();
    
    void set_strength(int new_strength);
    void add_strength(int added_strength);
    void sub_strength(int subbed_strength);
    int get_strength();

    void set_intellect(int new_intellect);
    void add_intellect(int added_intellect);
    void sub_intellect(int subbed_intellect);
    int get_intellect();

    void set_luck(int new_luck);
    void add_luck(int added_luck);
    void sub_luck(int subbed_luck);
    int get_luck();


    void add_spell(Spell new_spell);
    std::vector<Spell> get_spells();

};

void intro();
void story1(std::string name);
void story2(std::string name);

void next();
int cube6();
void stats_details();

void dealing_dmg(Creature &name1, Creature &name2, std::string type="physic");
void battle(Creature &name1, Creature &name2);

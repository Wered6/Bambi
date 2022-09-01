class Creature {

    std::string nickname;
    int hp;
    int mana;
    int strength;
    int intellect;
    int luck;

public:

    Creature(std::string new_nickname, int new_hp=100, int new_mana=100, int new_strength=5, int new_intellect=5, int new_luck=0);

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

};

void intro();
void story1(std::string name);
void story2(std::string name);

void next();
int cube6();
void stats_details();

void dealing_dmg(Creature &name1, Creature &name2, std::string type="physic");
void battle(Creature &name1, Creature &name2);

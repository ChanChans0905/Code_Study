#include <iostream>
#include <string.h>

class Marine{
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;

    public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, const char* marine_name);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};

Marine::Marine(){
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y){
    coord_x = x;
    coord_y = y;
    damage = 5;
    hp = 50;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name){
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    damage = 5;
    hp = 50;
    is_dead = false;
}

int Marine::attack(){
    return damage;
}

void Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if(hp <= 0) is_dead = true;
}

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

void Marine::show_status(){
    std::cout << "Marine" << name << std::endl;
    std::cout << "Location : " << coord_x << " , " << coord_y << std::endl;
    std::cout <<"HP : " << hp << std::endl;
}

int main(){
    Marine* marines[100];

    marines[0] = new Marine(2,3, "Marine 1");
    marines[1] = new Marine(5,3, "Marine 2");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "마린 1 -> 마린 2" << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}
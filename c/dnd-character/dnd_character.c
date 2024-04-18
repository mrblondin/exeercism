#include "dnd_character.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

int ability(void){
    srand(time(NULL));
    return rand() % 15 + 3;
}

int modifier(int score){
    return floor((score - 10) / (double) 2);
}

dnd_character_t make_dnd_character(void){
    dnd_character_t hero;

    hero.strength = ability();
    hero.dexterity = ability();
    hero.constitution = ability();
    hero.intelligence = ability();
    hero.wisdom = ability();
    hero.charisma = ability();

    hero.hitpoints = modifier(hero.constitution) + 10;

    return hero;
}

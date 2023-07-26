#include "Character_attributes.h"

Character_attributes::Character_attributes()
{
    character_name = {"H-iman", "BlackAnlu", "El-Canon", "Le-Kiwi", "Peter-Castlevania", "FeedUno"};
    character_base_attack = {18,19,16,17,18,19};
    character_special_skill = {25,24,27,26,25,24};
    life = 3;
}

std::string Character_attributes::getCharacter_name(int i)
{
    return character_name[i];
}

int Character_attributes::getCharacter_base_attack(int i)
{
    return character_base_attack[i];
}

int Character_attributes::getCharacter_special_skill(int i)
{
    return character_special_skill[i];
}

int Character_attributes::getlife()
{
    return life;
}

Character_attributes::~Character_attributes()
{
    
}
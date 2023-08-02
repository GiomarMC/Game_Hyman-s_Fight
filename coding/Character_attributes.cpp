#include "Character_attributes.h"

Character_attributes::Character_attributes()
{
    character_name = {"H-iman", "BlackAnlu", "El-Canon", "Le-Kiwi", "Peter-Castlevania", "FeedUno"};
    character_base_attack = {18,19,16,17,18,19};
    character_special_skill = {25,24,27,26,25,24};
    life = 3;
}

Character Character_attributes::getCharacterPorEleccion(int eleccion)
{
    if(eleccion >=1 && eleccion <= character_name.size())
    {
        int index = eleccion - 1 ;
        Character Personaje_Elegido;
        Personaje_Elegido.setName(character_name[index]);
        Personaje_Elegido.setBaseAttack(character_base_attack[index]);
        Personaje_Elegido.setSpecialSkill(character_special_skill[index]);
        Personaje_Elegido.setLife(life);
        return Personaje_Elegido;
    } 
    return Character();
}

std::string Character_attributes::getCharacter_name(int eleccion)
{
    return character_name[eleccion];
}

int Character_attributes::getCharacter_base_attack(int eleccion)
{
    return character_base_attack[eleccion];
}

int Character_attributes::getCharacter_special_skill(int eleccion)
{
    return character_special_skill[eleccion];
}

int Character_attributes::getlife()
{
    return life;
}

Character_attributes::~Character_attributes()
{
    
}
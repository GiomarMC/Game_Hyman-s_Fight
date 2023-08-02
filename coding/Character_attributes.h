#ifndef CHARACTER_ATTRIBUTES_H
#define CHARACTER_ATTRIBUTES_H

#include <vector>
#include <string>
#include "character_model.h"

class Character_attributes
{
    private:
        std::vector<std::string>character_name;
        std::vector<int>character_base_attack;
        std::vector<int>character_special_skill;
        int life;
    public:
        Character_attributes();
        Character getCharacterPorEleccion(int eleccion);
        std::string getCharacter_name(int);
        int getCharacter_base_attack(int);
        int getCharacter_special_skill(int);
        int getlife();
        ~Character_attributes();
};

#endif
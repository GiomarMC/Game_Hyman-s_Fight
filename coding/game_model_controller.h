#ifndef GAME_MODEL_CONTROLLER_H
#define GAME_MODEL_CONTROLLER_H

#include "character_model.h"
#include "Character_attributes.h"
#include <memory>

class Game_Model
{
    private:
        std::shared_ptr<Character> character;
        Character_attributes character_attributes;
    public:
        Game_Model();
        void initializeCharacter();
        void updateCharacter(float);
        std::shared_ptr<Character> getCharacter();
        ~Game_Model();
};

#endif
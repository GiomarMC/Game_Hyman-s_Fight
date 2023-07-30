#ifndef GAME_MODEL_CONTROLLER_H
#define GAME_MODEL_CONTROLLER_H

#include "character_model.h"
#include "Character_attributes.h"
#include "mapa_model.h"
#include <memory>

class Game_Model
{
    private:
        std::shared_ptr<Character> character;
        Character_attributes character_attributes;
        Mapa_model mapaModel;
    public:
        Game_Model();
        void initializeCharacter();
        void updateCharacter(float,float);
        std::shared_ptr<Character> getCharacter();
        void crearPlataformas();
        Mapa_model& getMapaModel();
        ~Game_Model();
};

#endif
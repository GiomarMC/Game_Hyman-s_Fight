#ifndef GAME_MODEL_CONTROLLER_H
#define GAME_MODEL_CONTROLLER_H

#include "character_model.h"
#include "Character_attributes.h"
#include "mapa_model.h"
#include "Menu_Model.h"
#include <memory>

class Game_Model
{
    private:
        std::shared_ptr<Character> character;
        Character_attributes character_attributes;
        Mapa_model mapaModel;
        CharacterMenu menuModel;
    public:
        Game_Model();
        void initializeCharacter();
        void updateCharacter(float);
        std::shared_ptr<Character> getCharacter();
        void crearPlataformas();
        Mapa_model& getMapaModel();
        void RunMenu(int, int);
        bool getIs_Finally() const;
        ~Game_Model();
};

#endif
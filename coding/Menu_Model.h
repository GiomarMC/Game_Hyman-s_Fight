#ifndef MENU_MODEL_H
#define MENU_MODEL_H

#include "character_model.h"
#include "Character_attributes.h"
#include <iostream>
#include <memory>

class CharacterMenu
{
    private:
        std::shared_ptr<bool> personajeSeleccionado;
        Character_attributes characterAttributes;
        std::shared_ptr<Character> selectedCharacter;
        std::shared_ptr<bool> is_Finally;

    public:
        CharacterMenu();
        void handleClick(int mouseX, int mouseY);
        void handleMapSelection(int mouseX, int mouseY);
        bool getIs_Finally() const;
        Character getSelectedCharacter() const;

};

#endif
#include "Menu_Model.h"
#include <iostream>


CharacterMenu::CharacterMenu() : personajeSeleccionado(false), is_Finally(false)
{
    
}

void CharacterMenu::handleClick(int mouseX, int mouseY)
{
    // Verificar si se hizo clic en uno de los botones azules
    for (int i = 0; i < 6; i++)
    {
        
        int squarePosX = 50 + 200 * i;
        int squarePosY = 300;
        int squareWidth = 100;
        int squareHeight = 110;

        if (mouseX >= squarePosX && mouseX <= squarePosX + squareWidth &&
            mouseY >= squarePosY && mouseY <= squarePosY + squareHeight)
        {
            selectedCharacter = characterAttributes.getCharacterPorEleccion(i + 1);
            std::cout << "#####################################" << std::endl;
            std::cout << "#- Informacion del Personaje:" << "     ##" << std::endl;
            std::cout << "#- Nombre: " << characterAttributes.getCharacter_name(i) << "                ##" << std::endl;
            std::cout << "#- Ataque Base: " << characterAttributes.getCharacter_base_attack(i) << "                 ##" << std::endl;
            std::cout << "#- Habilidad Especial: " << characterAttributes.getCharacter_special_skill(i) << "          ##" << std::endl;
            std::cout << "#- Vida: " << characterAttributes.getlife() << "                         ##" << std::endl;
            std::cout << "#####################################" << std::endl;
            std::cout << std::endl;
            personajeSeleccionado = true; // Establecer como verdadero al seleccionar un personaje

        }
    }
}
// Método para manejar la selección de mapas
void CharacterMenu::handleMapSelection(int mouseX, int mouseY)
{
    int selectedMap = -1;
    // Verificar si se hizo clic en uno de los botones amarillos (cuadrados) para selección de mapas
    for (int i = 0; i < 3; i++)
    {
        int buttonPosX = 100 + 350 * i;
        int buttonPosY = 100;
        int buttonWidth = 300;
        int buttonHeight = 300;

        // Verificar si el botón de selección del mapa 2 (map2) está siendo seleccionado
        if (i == 1)
        {
            buttonPosY = 450; // Ajustar la coordenada Y para el botón de selección del mapa 2 (map2)
        }

        if (mouseX >= buttonPosX && mouseX <= buttonPosX + buttonWidth &&
            mouseY >= buttonPosY && mouseY <= buttonPosY + buttonHeight)
        {

            std::cout << "Mapa seleccionado: Mapa " << i + 1 << std::endl;
            selectedMap = i + 1;
        }
    }
    is_Finally = true;
}

bool CharacterMenu::getIs_Finally() const {return is_Finally;}

Character CharacterMenu::getSelectedCharacter() const
{
    return selectedCharacter;
}

#include "game_model_controller.h"

Game_Model::Game_Model(): character(nullptr), character_attributes(), menuModel()
{

}

void Game_Model::initializeCharacter()
{
    int eleccion; // Asegúrate de inicializar eleccion con algún valor adecuado antes de usarlo
    character = std::make_shared<Character>();
    *character = character_attributes.getCharacterPorEleccion(eleccion);
    character->setX(100);
    character->setY(200);
}

void Game_Model::updateCharacter(float deltatime)
{
    character -> update(deltatime);
}

std::shared_ptr<Character> Game_Model::getCharacter()
{
    return character;
}

void Game_Model::crearPlataformas()
{
    mapaModel.crearPlataforma();
}

Mapa_model& Game_Model::getMapaModel()
{
    return mapaModel;
}

bool Game_Model::getIs_Finally() const {return menuModel.getIs_Finally();}

void Game_Model::RunMenu(int mouseX, int mouseY)
{
    menuModel.handleClick(mouseX,mouseY);
    menuModel.handleMapSelection(mouseX,mouseY);
}

Game_Model::~Game_Model()
{
    
}
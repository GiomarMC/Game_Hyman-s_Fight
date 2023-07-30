#include "game_model_controller.h"

Game_Model::Game_Model(): character(nullptr), character_attributes()
{

}

void Game_Model::initializeCharacter()
{
    character = std::make_shared<Character>();
    character -> setName(character_attributes.getCharacter_name(3));
    character -> setBaseAttack(character_attributes.getCharacter_base_attack(3));
    character -> setSpecialSkill(character_attributes.getCharacter_special_skill(3));
    character -> setLife(character_attributes.getlife());
    character -> setX(100);
    character -> setY(200);
}

void Game_Model::updateCharacter(float deltatime, float PosY)
{
    character -> update(deltatime,PosY);
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

Game_Model::~Game_Model()
{
    
}
#include "game_model.h"

Game_Model::Game_Model()
{
	char1.setpowerUp(nullptr);
}

character_1 Game_Model::getCharacter()
{
	return char1;
}
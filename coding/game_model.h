#ifndef GAME_MODEL_H
#define GAME_MODEL_H
//#include "character.h"
//#include <SFML/Graphics.hpp>
#include "character_1.h"


class Game_Model
{
	public:
		character_1 char1 = character_1();
	public:
		Game_Model();
		character_1 getCharacter();
};


#endif
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "character.h"
#include "personaje.h"

class Game
{
private:
    sf::RenderWindow window;
    character character;
    Personaje personaje;

public:
    Game();
    void run();
};

#endif
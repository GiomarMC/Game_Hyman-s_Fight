#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "sprite.h"

class Character_view
{
    private:
        float posX, posY;
        float deltaTime;
        sf::RectangleShape player;
        sf::Texture playerTexture;
        sf::Vector2f playertexturesize, playertexturecenter, playertexturecambio;
        sf::Clock clock;
        sf::RenderWindow window;
        Sprite sprite;
        
    public:
        Character_view(const std::string&);
        void setPosition(float, float);
        void draw(sf::RenderWindow&);
};

#endif
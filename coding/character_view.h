#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
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
        Character_view(const std::string& archivo, float x, float y);
        void setPosition(float x, float y);
        void draw(sf::RenderWindow& window);
        void run();
        
};

#endif
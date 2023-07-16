#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include "sprite.h"

class Character_view
{
    private:
        Sprite sprite;
        float posX, posY;
        sf::Keyboard::Key ultimatecla;

    public:
        Character_view(const std::string&);
        void setPosition(float, float);
        void draw(sf::RenderWindow&);
        void moveCharacterLeft();
        void moveCharacterRight();
    
    /*private:
        float posX, posY;
        float deltaTime;
        sf::RectangleShape player;
        sf::Texture playerTexture;
        sf::Vector2f playertexturesize, playertexturecenter, playertexturecambio;
        sf::Clock clock;
        sf::RenderWindow window;
        Sprite sprite;
        

    public:
        //Character_view();
        Character_view(const std::string&);
        void setPosition(float, float);
        void draw(sf::RenderWindow&);
        void run();*/        
};

#endif
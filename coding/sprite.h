#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

class Sprite
{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f center, cambio, tamano;

    public:
        Sprite(const std::string& archivo, float x, float y);
        void setPosition(float x, float y);
        void setScale(float scaleX, float scaleY);
        void draw(sf::RenderWindow& window);
};

#endif
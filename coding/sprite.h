#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Sprite
{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f center, cambio, tamano;
        int alto = 81;
        int ancho = 115;
        


    public:
        int indiceX = 0;
        int indiceY = 0;
        Sprite(const std::string& archivo, float x, float y);
        void setPosition(float x, float y);
        void setScale(float scaleX, float scaleY);
        void draw(sf::RenderWindow& window);
};

#endif
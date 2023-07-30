#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

class Sprite
{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f center;
        int fila;
        int columna;        

    public:
        Sprite(const std::string&);
        void setMove(int, int);
        void setNoMove(int, int, float);
        void setPosition(float, float);
        void setScale(float, float);
        void draw(sf::RenderWindow&);
        ~Sprite();
};

#endif
#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

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
        Sprite(const std::string& archivo);
        void setPosition(float, float);
        void setScale(float, float);
        void draw(sf::RenderWindow&);

    /*private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        
        float totalTime;
        float switchTime;

    public:
        sf::IntRect uvRect;
        Sprite(sf::Texture*, sf::Vector2u, float);
        void Update(int, float, bool);
        ~Sprite();*/
};

#endif
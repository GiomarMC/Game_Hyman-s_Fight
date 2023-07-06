#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Sprite
{
    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        
        float totalTime;
        float switchTime;

    public:
        sf::IntRect uvRect;

        Sprite(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        ~Sprite();

        void Update(int row, float deltaTime, bool faceright);
};

#endif
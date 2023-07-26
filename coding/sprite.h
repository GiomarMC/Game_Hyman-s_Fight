#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

class Sprite
{
    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        
        float totalTime;
        float switchTime;

    public:
        sf::IntRect uvRect;
        Sprite(sf::Texture*, sf::Vector2u, float);
        void Update(int, float, bool);
        ~Sprite();
};

#endif
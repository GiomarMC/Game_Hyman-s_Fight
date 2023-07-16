#include "sprite.h"

Sprite::Sprite(const std::string& archivo)
{
    texture.loadFromFile(archivo);
    sprite.setTexture(texture);
    tamano = sf::Vector2f(texture.getSize().x, texture.getSize().y);
    center = sf::Vector2f(0, 0);
    cambio = sf::Vector2f(0, 0);
}

void Sprite::setPosition(float x, float y)
{
    center.x = x;
    center.y = y;
}

void Sprite::setScale(float scaleX, float scaleY)
{
    sprite.setScale(scaleX, scaleY);
}

void Sprite::draw(sf::RenderWindow& window)
{
    sprite.setPosition(center);
    window.draw(sprite);
}

/*Sprite::Sprite(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

Sprite::~Sprite()
{

} 

void Sprite::Update(int row, float deltaTime, bool faceright)
{
    currentImage.y = row;
    totalTime += deltaTime;

    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;

        }
    }

    uvRect.top = currentImage.y * uvRect.height;

    if (faceright)
    {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    } 
    else 
    {
        uvRect.left = (currentImage.x + 1)* abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}*/
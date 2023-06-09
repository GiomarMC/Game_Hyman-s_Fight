#include "sprite.h"

Sprite::Sprite(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
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
}
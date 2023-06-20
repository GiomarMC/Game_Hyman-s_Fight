#include "sprite.h"

Sprite::Sprite(const std::string& archivo, float x, float y)
{
    texture.loadFromFile(archivo);
    sprite.setTexture(texture);
    tamano = sf::Vector2f(texture.getSize().x, texture.getSize().y);
    center = sf::Vector2f(x, y);
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
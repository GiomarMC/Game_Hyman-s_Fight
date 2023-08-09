#include "sprite.h"
#include <iostream>

Sprite::Sprite(const std::string& archivo)
{
    texture = std::make_shared<sf::Texture>();
    if (!texture -> loadFromFile(archivo))
    {
        std::cout << "Error al cargar la imagen: " << archivo << std::endl;
    }
    sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
    sprite.setTexture(*texture);
    center = sf::Vector2f(200, 400);
    columna = 0;
    //std::cout << sprite.getGlobalBounds().width << ", " << sprite.getGlobalBounds().height;
}

void Sprite::setMove(int fila, int limit){
    this->fila = fila;
    columna++;
    columna = columna % limit;
    sprite.setTextureRect(sf::IntRect(columna * 120, fila * 120, 120, 120));
}

void Sprite::setNoMove(int fila, int limit, float deltaTime){
    this->fila = fila;
    columna++;
    columna = columna % limit;
    sprite.setTextureRect(sf::IntRect(columna * 120, fila * 120, 120, 120)); 
}

void Sprite::setPosition(float x, float y)
{
    center.x = x;
    center.y = y;
}

void Sprite::setScale(float scaleX, float scaleY)
{
    sprite.setScale(scaleX, scaleY);
    //std::cout << sprite.getGlobalBounds().width << ", " << sprite.getGlobalBounds().height;
}

void Sprite::draw(sf::RenderWindow& window)
{
    sprite.setPosition(center);
    window.draw(sprite);
}

Sprite::~Sprite()
{

} 
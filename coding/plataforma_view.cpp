#include "plataforma_view.h"

Plataforma_view::Plataforma_view(const std::string& path)
{
    texture = std::make_shared<sf::Texture>();
    if(!texture -> loadFromFile(path))
    {
        std::cout << "Error al cargar la imagen";
    }
    plataformShape.setTexture(*texture);
}

void Plataforma_view::setPlataformData(float x, float y, float width, float height)
{
    posX = x;
    posY = y;
    plataformShape.setPosition(posX,posY);
    plataformShape.setScale(width/plataformShape.getLocalBounds().width,height/plataformShape.getLocalBounds().height);
}

void Plataforma_view::drawPlataform(sf::RenderWindow& window)
{
    window.draw(plataformShape);
}

float Plataforma_view::getPosX() const {return posX;}

float Plataforma_view::getPosY() const {return posY;}

float Plataforma_view::getWidth() const {return plataformShape.getLocalBounds().width;}

float Plataforma_view::getHeight() const {return plataformShape.getLocalBounds().height;}
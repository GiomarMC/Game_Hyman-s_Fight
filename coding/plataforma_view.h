#ifndef MAPA_VIEW_H
#define MAPA_VIEW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Plataforma_view
{
    private:
        std::shared_ptr<sf::Texture> texture;
        sf::Sprite plataformShape;
        float posX, posY;
    public:
        Plataforma_view(const std::string&);
        void setPlataformData(float,float,float,float);
        void drawPlataform(sf::RenderWindow&);
        float getPosX() const;
        float getPosY() const;
        float getWidth() const;
        float getHeight() const;
};

#endif
#include "plataforma_model.h"

Plataforma::Plataforma()
{
    PosX = std::make_shared<float>(0);
    PosY = std::make_shared<float>(0);
    width = std::make_shared<float>(0);
    height = std::make_shared<float>(0);
}

float Plataforma::getPosX() const {return *PosX;}

float Plataforma::getPosY() const {return *PosY;}

float Plataforma::getWidth() const {return *width;}

float Plataforma::getHeight() const {return *height;}

void Plataforma::setPosition(float posx, float posy)
{
    *PosX = posx;
    *PosY = posy;
}

void Plataforma::setHeight(float Height)
{
    *height = Height;
}

void Plataforma::setWidth(float Width)
{
    *width = Width;
}
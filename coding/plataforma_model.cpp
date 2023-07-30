#include "plataforma_model.h"

Plataforma::Plataforma(): PosX(0), PosY(0), width(0), height(0)
{

}

float Plataforma::getPosX() const {return PosX;}

float Plataforma::getPosY() const {return PosY;}

float Plataforma::getWidth() const {return width;}

float Plataforma::getHeight() const {return height;}

void Plataforma::setPosition(float posx, float posy)
{
    PosX = posx;
    PosY = posy;
}

void Plataforma::setHeight(float Height)
{
    height = Height;
}

void Plataforma::setWidth(float Width)
{
    width = Width;
}
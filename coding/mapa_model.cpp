#include "mapa_model.h"

Mapa_model::Mapa_model()
{

}

void Mapa_model::crearPlataforma()
{
    const int WindowHeight = 600;
    const int PlatformWidth = 200;
    const int PlatformHeight = 150;

    int y_mid = WindowHeight/2 - PlatformHeight/2;
    int x_mid = (800 - PlatformWidth)/2;

    std::shared_ptr<Plataforma> plataforma1 = std::make_shared<Plataforma>();
    plataforma1 -> setPosition(100, 225);
    plataforma1 -> setWidth(PlatformWidth);
    plataforma1 -> setHeight(PlatformHeight);
    plataforma.push_back(plataforma1);

    std::shared_ptr<Plataforma> plataforma2 = std::make_shared<Plataforma>();
    plataforma2 -> setPosition(500, 225);
    plataforma2 -> setWidth(PlatformWidth);
    plataforma2 -> setHeight(PlatformHeight);
    plataforma.push_back(plataforma2);

    int y_3_4 = WindowHeight * 3/4 - PlatformHeight/2;

    std::shared_ptr<Plataforma> plataforma3 = std::make_shared<Plataforma>();
    plataforma3 -> setPosition(800/2 - PlatformWidth/2, 300);
    plataforma3 -> setWidth(PlatformWidth);
    plataforma3 -> setHeight(PlatformHeight);
    plataforma.push_back(plataforma3);
}

const std::vector<std::shared_ptr<Plataforma>>& Mapa_model::getPlataformas() const
{
    return plataforma;
}
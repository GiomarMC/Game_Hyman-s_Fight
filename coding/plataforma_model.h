#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <memory>

class Plataforma
{
    private:
        std::shared_ptr<float> PosX;
        std::shared_ptr<float> PosY;
        std::shared_ptr<float> width;
        std::shared_ptr<float> height;
    public:
        Plataforma();
        float getPosX() const;
        float getPosY() const;
        float getWidth() const;
        float getHeight() const;
        void setPosition(float, float);
        void setWidth(float);
        void setHeight(float);
};

#endif
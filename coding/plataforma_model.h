#ifndef PLATAFORMA_H
#define PLATAFORMA_H

class Plataforma
{
    private:
        float PosX, PosY, width, height;
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
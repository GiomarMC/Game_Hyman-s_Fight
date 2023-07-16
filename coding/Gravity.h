#ifndef GRAVITY_H
#define GRAVITY_H

template <typename T>
class Gravity
{
    private:
        const float gravity = 9.8;
    public:
        void ApplyGravity(T&,float);
};

template <class T> void Gravity<T>::ApplyGravity(T& object, float deltaTime)
{
    float falldistance = gravity * deltaTime;
    object.setY(object.getY() + falldistance);
}

#endif
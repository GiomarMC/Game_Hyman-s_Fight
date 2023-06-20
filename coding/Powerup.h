#include <iostream>

class PowerUp
{
    public:
        virtual void aplicarPowerUp() = 0;
        virtual ~PowerUp(){}
};

class DobleVidaPowerUp : public PowerUp
{
    public:
        void aplicarPowerUp() override
        {
            std::cout << "Doble vida obtenida!" << std::endl;	
        }
        ~DobleVidaPowerUp(){}	
};

class CuracionPowerUp : public PowerUp
{
    public:
        void aplicarPowerUp() override
        {
            std::cout << "Has obtenido un plus de salud!" << std::endl;
        }
        ~CuracionPowerUp(){}	
};

class VelocidadMovPowerUp : public PowerUp
{
    public:
        void aplicarPowerUp() override
        {
            std::cout << "Velocidad de movimiento Aumentada!" << std::endl;
        }
        ~VelocidadMovPowerUp(){}
};
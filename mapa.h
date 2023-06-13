#include <SFML/Graphics.hpp>

class Mapa
{
    public:
        Mapa()
        {
            cargarTexturas();
            crearMapa();//Inicializa los metodos
        }
        void dibujar(sf::RenderWindow& ventana)
        {
            ventana.draw(spriteMapa_);//Dibuja el Mapa
        }
    private:
        sf::Texture texturaMapa_;
        sf::Sprite spriteMapa_;
        void cargarTexturas()
        {
            if (!texturaMapa_.loadFromFile("mapa.png"))
            {
                //carga el mapa desde un archivo
            }
        }
        void crearMapa()
        {
            spriteMapa_.setTexture(texturaMapa_);//configura el sprite del mapa
        }
};
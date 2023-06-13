#include <SFML/Graphics.hpp> //incluye la biblioteca SFML, específicamente el módulo Graphics

class Sprite //encapsula la lógica y los datos necesarios para mostrar y manipular un sprite en la ventana
{
    // Variables miembro
    sf::Texture texture; //proporciona funcionalidad para cargar y manipular texturas de imágenes
    sf::Sprite sprite; //se utiliza en conjunto con la clase sf::Texture para asignar una textura al sprite y controlar su posición, escala, rotación, y más
    sf::Vector2f center, cambio, tamano; //clase proporcionada por la biblioteca SFML que representa un vector de dos componentes de tipo float. Es utilizada para representar posiciones, desplazamientos o tamaños en un espacio bidimensional.
    int tipo, num;

    public:
        // 3 constructores
        Sprite(const std::string& archivo, float x, float y)
        {
            texture.loadFromFile(archivo);
            sprite.setTexture(texture);
            tamano = sf::Vector2f(texture.getSize().x, texture.getSize().y);
            center = sf::Vector2f(x, y);
            cambio = sf::Vector2f(0, 0);
            tipo = 0;
            num = 0;
        }

        Sprite(const std::string& archivo, int pared)
        {
            texture.loadFromFile(archivo);
            sprite.setTexture(texture);
            tamano = sf::Vector2f(texture.getSize().x, texture.getSize().y);
            center = sf::Vector2f(0, 0);
            cambio = sf::Vector2f(0, 0);
            tipo = 0;
            num = pared;
        }

        Sprite(float x, float y)
        {
            tamano = sf::Vector2f(0, 0);
            center = sf::Vector2f(x, y);
            cambio = sf::Vector2f(0, 0);
            tipo = 0;
        }

        // Métodos
        void mostrar(sf::RenderWindow& window)
        { //actualiza la posición del sprite sumando el desplazamiento (cambio) al centro (center)
            center.x += cambio.x; // Genera movimiento
            center.y += cambio.y;
            sprite.setPosition(center);
            window.draw(sprite);
        }

        //Permiten establecer y obtener los límites izquierdo, derecho, superior e inferior del sprite en función de su centro y tamaño.

        void setLeft(float left)
        {
            center.x += left + tamano.x / 2;
        }

        float getLeft()
        {
            return center.x - tamano.x / 2;
        }

        void setRight(float right)
        {
            center.x += right - tamano.x / 2;
        }

        float getRight()
        {
            return center.x + tamano.x / 2;
        }

        void setTop(float top)
        {
            center.y += top + tamano.x / 2;
        }

        float getTop()
        {
            return center.y - tamano.x / 2;
        }

        void setBottom(float bottom)
        {
            center.y += bottom - tamano.x / 2;
        }

        float getBottom()
        {
            return center.y + tamano.x / 2;
        }
};
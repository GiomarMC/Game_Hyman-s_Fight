#ifndef MAPA_MODEL_H
#define MAPA_MODEL_H

#include <string>
#include <vector>
#include "plataforma_model.h"

class Mapa_model
{
    private:
        std::vector<Plataforma> plataforma;
    public:
        Mapa_model();
        void crearPlataforma();
        const std::vector<Plataforma>& getPlataformas() const;
};

#endif
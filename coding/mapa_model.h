#ifndef MAPA_MODEL_H
#define MAPA_MODEL_H

#include <string>
#include <vector>
#include "plataforma_model.h"
#include <memory>

class Mapa_model
{
    private:
        std::vector<std::shared_ptr<Plataforma>> plataforma;
    public:
        Mapa_model();
        void crearPlataforma();
        const std::vector<std::shared_ptr<Plataforma>>& getPlataformas() const;
};

#endif
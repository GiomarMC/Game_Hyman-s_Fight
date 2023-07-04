#ifndef MODEL_CONTROLLER_H
#define MODEL_CONTROLLER_H

#include "character_model.h"
#include "Character_attributes.h"

class Model_controller
{
    private:
        Character character;
        Character_attributes character_attributes;
    public:
        Model_controller();
};

#endif
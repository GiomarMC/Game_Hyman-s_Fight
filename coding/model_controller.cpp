#include "model_controller.h"

Model_controller::Model_controller()
{
    character.setName(character_attributes.getCharacter_name(3));
    character.setBaseAttack(character_attributes.getCharacter_base_attack(3));
    character.setSpecialSkill(character_attributes.getCharacter_special_skill(3));
    character.setLife(character_attributes.getlife());
    character.setX(200);
    character.setY(200);
}
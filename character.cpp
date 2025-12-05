#include "character.h"
#include <string>
Character::Character(std::string Texture, AbstractController* controller) :Texture(Texture){}

Input Character::move()
{
    return controller->move();
}

void Character::setController(AbstractController *controller)
{
    this->controller= controller;
}

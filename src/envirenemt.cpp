#include <iostream>
#include "envirenemt.hpp"
#include "element.hpp"


envirnement::envirnement(float gravity, float wind, float friction){
    this->gravity = gravity;
    this->wind = wind;
    this->friction = friction;
}

void envirnement::set_gravity(float gravity){
    this->gravity = gravity;
}

void envirnement::set_wind(float wind){
    this->wind = wind;
}

void envirnement::set_friction(float friction){
    this->friction = friction;
}

void envirnement::add_element(element el){
    this->elements.push_back(el);
}

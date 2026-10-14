#include <iostream>
#include "../include/environment.hpp"
#include "../include/element.hpp"
#include "vector"


environment::environment(float gravity, float wind, float friction)
    : gravity(gravity), wind(wind), friction(friction){
}

void environment::set_gravity(float gravity){
    this->gravity = gravity;
}

void environment::set_wind(float wind){
    this->wind = wind;
}

void environment::set_friction(float friction){
    this->friction = friction;
}

void environment::addElement(element ele){
    this->elements.emplace_back(ele);
}


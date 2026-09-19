#include <iostream>
#include "environment.hpp"
#include "element.hpp"


environment::environment(float gravity, float wind, float friction, element el)
    : gravity(gravity), wind(wind), friction(friction), el(el){
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



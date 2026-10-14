#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "element.hpp"

class environment{
    public: float gravity;
    public: float wind;
    public: float friction;
    std::vector<element> elements;

    environment(float gravity, float wind, float friction);

    void set_gravity(float gravity);
    void set_wind(float wind);
    void set_friction(float friction);

    void applyWind(element el);
    void addElement(element ele);
};
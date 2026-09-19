#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "element.hpp"

class environment{
    public: float gravity;
    public: float wind;
    public: float friction;
    public: element el;

    environment(float gravity, float wind, float friction, element el);

    void set_gravity(float gravity);
    void set_wind(float wind);
    void set_friction(float friction);

    void applyGravity(element el);
    void applyWind(element el);
};
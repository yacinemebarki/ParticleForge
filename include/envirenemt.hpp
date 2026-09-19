#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "element.hpp"

class envirnement{
    public: float gravity;
    public: float wind;
    public: float friction;
    std::vector<element> elements;

    envirnement(float gravity, float wind, float friction);

    void set_gravity(float gravity);
    void set_wind(float wind);
    void set_friction(float friction);

    void add_element(element el);
    void applyGravity(element el);
    void applyWind(element el);
};
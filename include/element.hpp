#pragma once
#include <SFML/Graphics.hpp>

class element{
    public: float weight;
    public: float restitution;
    public: sf::Vector2f position;
    public: sf::CircleShape shape;
    public: sf::Vector2f velocity;

    element(float weight, float restitution, sf::Vector2f position, sf::Color color = sf::Color::Cyan);

    void setPostion(sf::Vector2f position);
    void set_weight(float weight);
    void set_restitution(float restitution);
    

};
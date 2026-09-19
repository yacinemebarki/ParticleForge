#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class element{
    public: float weight;
    public: float restitution;
    public: sf::Vector2f position;
    public: sf::Texture texture;
    public: sf::Sprite sprite;

    element(float weight, float restitution, sf::Vector2f position, std::string imagePath);

    void setPostion(sf::Vector2f position);
    void set_weight(float weight);
    void set_restitution(float restitution);
    

};
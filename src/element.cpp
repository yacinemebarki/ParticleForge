#include <istream>
#include "../include/element.hpp"
#include <SFML/Graphics.hpp>

element::element(float weight, float restitution, sf::Vector2f position, std::string imagePath){
    this->weight = weight;
    this->restitution = restitution;
    this->position = position;
    
    velocity = sf::Vector2f(0.f, 0.f);

    texture.loadFromFile(imagePath);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void element::set_restitution(float restitution){
    this->restitution = restitution;
}

void element::set_weight(float weight){
    this->weight = weight;
}

void element::setPostion(sf::Vector2f position){
    this->position = position;
    sprite.setPosition(position);
}




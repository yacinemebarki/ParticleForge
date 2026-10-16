#include "../include/element.hpp"

element::element(float weight, float restitution, sf::Vector2f position, sf::Color color){
    this->weight = weight;
    this->restitution = restitution;
    this->position = position;
    
    velocity = sf::Vector2f(0.f, 0.f);

    shape.setRadius(30.f);
    shape.setFillColor(color);
    shape.setPosition(position);
}

void element::set_restitution(float restitution){
    this->restitution = restitution;
}

void element::set_weight(float weight){
    this->weight = weight;
}

void element::setPostion(sf::Vector2f position){
    this->position = position;
    shape.setPosition(position);
}



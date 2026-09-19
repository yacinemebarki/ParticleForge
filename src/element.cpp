#include <istream>
#include "element.hpp"
#include <SFML/Graphics.hpp>

element::element(float weight, float restitution, sf::Vector2f postion, std::string imagePath){
    this->weight = weight;
    this->restitution = restitution;
    this->position = position;
    

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

void element::setPostion(sf::Vector2f postion){
    this->position = position;
}




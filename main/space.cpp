#include <SFML/Graphics.hpp>
#include <istream>

#include <string>

std::string background_image = "../../image/backgroudn.avif";
void OpenApp(){
    sf::RenderWindow window(sf::VideoMode(1280, 730), "tiny_physic");
    
    while (window.isOpen()){
        window.clear();
        window.display();
    }
    
    
}

int main(){
    OpenApp();
}


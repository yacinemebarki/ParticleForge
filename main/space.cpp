#include <SFML/Graphics.hpp>
#include <istream>

#include <string>

std::string background_image = "../../image/backgroudn.avif";
void OpenApp(){
    sf::RenderWindow window(sf::VideoMode(1280, 730), "tiny_physic");

    //styling the text
    sf::Font title_font;
    title_font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    sf::Text title;
    title.setFont(title_font);
    title.setString("tiny physic");
    title.setColor(sf::Color::Red);

    //pause and restart buttons
    sf::RectangleShape restart_btn(sf::Vector2f(60, 30));
    restart_btn.setFillColor(sf::Color::Blue);
    


    
    while (window.isOpen()){
        window.clear();
        window.display();
    }
    
    
}

int main(){
    OpenApp();
}


#include <SFML/Graphics.hpp>
#include <istream>

#include <string>

std::string background_image = "../../image/backgroudn.avif";

void setupText(sf::Text& text, sf::Font& font, const std::string& content,sf::Color color){
    text.setFont(font);
    text.setString(content);
    text.setFillColor(color);
}

struct IntroPanel{
    sf::RectangleShape restartButton;
    sf::RectangleShape pauseButton;
    sf::Text title;
    sf::Text restartText;
    sf::Text pauseText;
};

void setupIntroPanel(IntroPanel& panel, sf::Font &font){
    const float panelY = 30.f;
    const float buttonWidth = 100.f;
    const float buttonHeight = 30.f;
    const float buttonGap = 20.f;

    // Title
    setupText(panel.title, font, "tiny physic", sf::Color::Red);

    panel.title.setCharacterSize(24);
    panel.title.setPosition(20.f, panelY);


    // Restart button
    panel.restartButton.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    panel.restartButton.setFillColor(sf::Color::Blue);
    panel.restartButton.setPosition(850.f, panelY);

    setupText(panel.restartText, font, "restart", sf::Color::Black);

    panel.restartText.setCharacterSize(14);
    panel.restartText.setPosition(870.f, panelY + 6.f);


    // Pause button
    panel.pauseButton.setSize(sf::Vector2f(buttonWidth, buttonHeight));

    panel.pauseButton.setFillColor(sf::Color::Green);
    panel.pauseButton.setPosition(850.f + buttonWidth + buttonGap, panelY);

    setupText(panel.pauseText, font, "pause", sf::Color::Black);

    panel.pauseText.setCharacterSize(14);
    panel.pauseText.setPosition(990.f, panelY + 6.f);
}

struct PhysicSetting{
    sf::Text label;
    sf::RectangleShape bar;
    sf::CircleShape knob;
    float min_value;
    float max_value;
    float value;
};

struct PhysicPanel{
    PhysicSetting gravity;
    PhysicSetting wind;
    PhysicSetting weight;
    PhysicSetting restitution;
    PhysicSetting friction;
};

void setupPhysicSetting(PhysicSetting& setting, sf::Font& font, std::string label, float min_value, float max_value, float value,sf::Vector2f postion){
    setting.min_value = min_value;
    setting.max_value = max_value;
    setting.value = value;

    setting.bar.setSize(sf::Vector2f(250, 6));
    setting.bar.setFillColor(sf::Color::White);
    setting.bar.setPosition(postion);

    setting.knob.setRadius(8);
    setting.knob.setFillColor(sf::Color::White);
    float ration = (value - min_value) / (value - max_value);
    setting.bar.setPosition(postion.x + ration * 250 - 8, postion.y - 5);

    setupText(setting.label, font, label, sf::Color:: White);
    setting.label.setCharacterSize(16);
    setting.label.setPosition(postion.x, postion.y - 30);

}

void setupPhysicPanel(PhysicPanel& panel, sf::Font& font){
    const float min_Panelx = 850;  
    
    
}

void OpenApp(){
    sf::RenderWindow window(sf::VideoMode(1280, 730), "tiny_physic");

    IntroPanel intro;
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    setupIntroPanel(intro, font);

    while (window.isOpen()){
        window.clear();
        window.draw(intro.title);
        window.draw(intro.pauseButton);
        window.draw(intro.pauseText);
        window.draw(intro.restartButton);
        window.draw(intro.restartText);
        window.display();
    }
    
    
}

int main(){
    OpenApp();
}


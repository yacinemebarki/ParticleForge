#include <SFML/Graphics.hpp>
#include <iostream>

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
    sf::Text title;
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
    float ration = (value - min_value) / (max_value - min_value);
    setting.knob.setPosition(postion.x + ration * 250 - 8, postion.y - 5);

    setupText(setting.label, font, label, sf::Color:: White);
    setting.label.setCharacterSize(16);
    setting.label.setPosition(postion.x, postion.y - 30);

}

void drawPhysicSetting(sf::RenderWindow& window, const PhysicSetting& setting){
    window.draw(setting.label);
    window.draw(setting.bar);
    window.draw(setting.knob);
}

void setupPhysicPanel(PhysicPanel& panel, sf::Font& font){
    const float min_Panel_x = 850;
    const float min_Panel_y = 80;
    const float bar_gap = 40;
    const float bar_x = 900;
    float current_y = 120;

    //title
    setupText(panel.title, font, "physic settings", sf::Color::Red);
    panel.title.setPosition(min_Panel_x, min_Panel_y);
    current_y += bar_gap;

    sf::Vector2f postion(bar_x, current_y);
    setupPhysicSetting(panel.gravity, font, "gravity", 0, 30, 9.8, postion);
    postion.y += bar_gap;

    setupPhysicSetting(panel.wind, font, "wind", -30, 30, 0, postion);
    postion.y += bar_gap;

    setupPhysicSetting(panel.weight, font, "weight", 0, 1000, 20, postion);
    postion.y += bar_gap;

    setupPhysicSetting(panel.friction, font, "friction", 0, 1, 0.3, postion);
    postion.y += bar_gap;

    setupPhysicSetting(panel.restitution, font, "restitution", 0, 1, 0.7, postion);

}

void handlIntroEvent(sf::Event &event, IntroPanel &intro){
    if(event.type == sf::Event::MouseButtonPressed){
        sf::Vector2f mouse(event.mouseButton.x, event.mouseButton.y);
        if(intro.restartButton.getGlobalBounds().contains(mouse)){
            std::cout <<"restart pressed";
        }
        if(intro.pauseButton.getGlobalBounds().contains(mouse)){
            std::cout <<"pause pressed";
        }
    }
}

void handelSettingEvent(sf::Event &event, PhysicPanel &physic);

void handelEvent(sf::RenderWindow &window, IntroPanel &intro, PhysicPanel &physic){
    sf::Event event;

    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
        handlIntroEvent(event, intro);
        handelSettingEvent(event, physic);
    }
}

void OpenApp(){
    sf::RenderWindow window(sf::VideoMode(1280, 730), "tiny_physic");

    IntroPanel intro;
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    setupIntroPanel(intro, font);

    PhysicPanel Physical;
    setupPhysicPanel(Physical, font);

    while (window.isOpen()){
        window.clear();

        window.draw(intro.title);
        window.draw(intro.pauseButton);
        window.draw(intro.pauseText);
        window.draw(intro.restartButton);
        window.draw(intro.restartText);

        window.draw(Physical.title);
        drawPhysicSetting(window, Physical.gravity);
        drawPhysicSetting(window, Physical.wind);
        drawPhysicSetting(window, Physical.weight);
        drawPhysicSetting(window, Physical.friction);
        drawPhysicSetting(window, Physical.restitution);

        window.display();
    }
    
    
}

int main(){
    OpenApp();
}


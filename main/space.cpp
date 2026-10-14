#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../include/element.hpp"
#include "../include/environment.hpp"
#include <thread>
#include <mutex>

std::string background_image = "../../image/backgroudn.avif";

void setupText(sf::Text &text, sf::Font &font, const std::string &content, sf::Color color)
{
    text.setFont(font);
    text.setString(content);
    text.setFillColor(color);
}

struct IntroPanel
{
    sf::RectangleShape restartButton;
    sf::RectangleShape pauseButton;
    sf::Text title;
    sf::Text restartText;
    sf::Text pauseText;
};

void setupIntroPanel(IntroPanel &panel, sf::Font &font)
{
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

struct PhysicSetting
{
    sf::Text label;
    sf::RectangleShape bar;
    sf::CircleShape knob;
    float min_value;
    float max_value;
    float value;
};

struct PhysicPanel
{
    sf::Text title;
    PhysicSetting gravity;
    PhysicSetting wind;
    PhysicSetting weight;
    PhysicSetting restitution;
    PhysicSetting friction;
};

void setupPhysicSetting(PhysicSetting &setting, sf::Font &font, std::string label, float min_value, float max_value, float value, sf::Vector2f postion)
{
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

    setupText(setting.label, font, label, sf::Color::White);
    setting.label.setCharacterSize(16);
    setting.label.setPosition(postion.x, postion.y - 30);
}

void drawPhysicSetting(sf::RenderWindow &window, const PhysicSetting &setting)
{
    window.draw(setting.label);
    window.draw(setting.bar);
    window.draw(setting.knob);
}

void setupPhysicPanel(PhysicPanel &panel, sf::Font &font)
{
    const float min_Panel_x = 850;
    const float min_Panel_y = 80;
    const float bar_gap = 40;
    const float bar_x = 900;
    float current_y = 120;

    // title
    setupText(panel.title, font, "physic settings", sf::Color::Red);
    panel.title.setPosition(min_Panel_x, min_Panel_y);
    current_y += bar_gap;

    sf::Vector2f postion(bar_x, current_y);
    setupPhysicSetting(panel.gravity, font, "gravity", 0, 30, 9.8, postion);
    postion.y += bar_gap;

    setupPhysicSetting(panel.wind, font, "wind", -30, 30, 0, postion);
    postion.y += bar_gap;

    setupPhysicSetting(panel.weight, font, "weight", 0.1f, 1000.f, 20.f, postion);
    postion.y += bar_gap;

    setupPhysicSetting(panel.friction, font, "friction", 0, 1, 0.3, postion);
    postion.y += bar_gap;

    setupPhysicSetting(panel.restitution, font, "restitution", 0, 1, 0.7, postion);
}

bool paused = false;
bool resart = false;
bool running = true;
std::mutex physicsMutex;

void handlIntroEvent(sf::Event &event, IntroPanel &intro)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2f mouse(event.mouseButton.x, event.mouseButton.y);
        if (intro.restartButton.getGlobalBounds().contains(mouse))
        {
            std::cout << "restart pressed";
            paused = false;
            resart = true;
        }
        if (intro.pauseButton.getGlobalBounds().contains(mouse))
        {
            std::cout << "pause pressed";
            paused = !paused;
        }
    }
}

void updatePhysicSetting(PhysicSetting &setting, float mouseX)
{
    float barx = setting.bar.getPosition().x;
    float barWidth = setting.bar.getSize().x;

    float ratio = (mouseX - barx) / barWidth;
    if (ratio < 0)
    {
        ratio = 0;
    }
    else if (ratio > 1)
    {
        ratio = 1;
    }

    setting.value = setting.min_value + ratio * (setting.max_value - setting.min_value);
    std::cout << setting.value;

    setting.knob.setPosition(barx + ratio * barWidth - setting.knob.getRadius(), setting.bar.getPosition().y - 5);
}

bool isMouseOverSetting(PhysicSetting &setting, sf::Vector2f mouse)
{
    sf::FloatRect area = setting.bar.getGlobalBounds();

    area.top -= 10;
    area.height += 20;

    return area.contains(mouse);
}

void handelSettingEvent(sf::Event &event, PhysicPanel &panel)
{
    if (event.type != sf::Event::MouseButtonPressed)
        return;

    if (event.mouseButton.button != sf::Mouse::Left)
        return;

    sf::Vector2f mouse(event.mouseButton.x, event.mouseButton.y);

    if (isMouseOverSetting(panel.gravity, mouse))
    {
        updatePhysicSetting(panel.gravity, mouse.x);
    }

    else if (isMouseOverSetting(panel.wind, mouse))
    {
        updatePhysicSetting(panel.wind, mouse.x);
    }

    else if (isMouseOverSetting(panel.weight, mouse))
    {
        updatePhysicSetting(panel.weight, mouse.x);
    }

    else if (isMouseOverSetting(panel.friction, mouse))
    {
        updatePhysicSetting(panel.friction, mouse.x);
    }

    else if (isMouseOverSetting(panel.restitution, mouse))
    {
        updatePhysicSetting(panel.restitution, mouse.x);
    }
}

void handelEvent(sf::RenderWindow &window, IntroPanel &intro, PhysicPanel &physic)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        handlIntroEvent(event, intro);
        handelSettingEvent(event, physic);
    }
}

float dt = 0.016f;

sf::Vector2f gravityForce(element &el, environment &env)
{
    float force = env.gravity * el.weight;
    return sf::Vector2f(0, force);
}

sf::Vector2f WindForce(environment &env)
{
    return sf::Vector2f(env.wind, 0);
}

void applyFriction(element &el, environment &env)
{
    float amount = env.friction * dt;

    if (el.velocity.x > 0.f)
    {
        el.velocity.x = std::max(0.f, el.velocity.x - amount);
    }
    else if (el.velocity.x < 0.f)
    {
        el.velocity.x = std::min(0.f, el.velocity.x + amount);
    }
}

void checkFloorCollision(element &el, float floorY)
{
    if (el.position.y >= floorY)
    {
        el.position.y = floorY;
        el.velocity.y = -el.velocity.y * el.restitution;
    }
}

void physicLogic(PhysicPanel &physic, environment &env)
{
    env.set_wind(physic.wind.value);
    env.set_gravity(physic.gravity.value);
    env.set_friction(physic.friction.value);

    for (element &el : env.elements)
    {
        el.set_restitution(physic.restitution.value);
        el.set_weight(physic.weight.value);

        if (el.weight <= 0.f)
            continue;

        sf::Vector2f gf = gravityForce(el, env);
        sf::Vector2f wf = WindForce(env);
        sf::Vector2f totalForce = gf + wf;
        sf::Vector2f acceleration = totalForce / el.weight;

        el.velocity += acceleration * dt;
        sf::Vector2f new_pos = el.position + el.velocity * dt;
        el.setPostion(new_pos);
    }
}

void applyForces(PhysicPanel &Physical,environment &env){
    std::cout<<"enter";
    while(running){
        if(!paused){
            std::lock_guard<std::mutex> lock(physicsMutex);
            physicLogic(Physical, env);
            for (element &el : env.elements)
            {
                checkFloorCollision(el, 710);
                applyFriction(el, env);
            }           
       }
       std::this_thread::sleep_for(std::chrono::milliseconds(16));
        
    }
    
}

void OpenApp()
{
    sf::RenderWindow window(sf::VideoMode(1280, 730), "tiny_physic");

    IntroPanel intro;
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    setupIntroPanel(intro, font);

    PhysicPanel Physical;
    setupPhysicPanel(Physical, font);

    element el(2, 0.8, sf::Vector2f(300.f, 100.f), "image/Bird.png");
    environment env(9.8, 15, 0.5);
    env.addElement(el);

    std::thread Force([&] () {
        applyForces(Physical, env);
    });

    while (window.isOpen())
    {
        window.clear();

        window.draw(intro.title);
        window.draw(intro.pauseButton);
        window.draw(intro.pauseText);
        window.draw(intro.restartButton);
        window.draw(intro.restartText);

        window.draw(Physical.title);
        for (element &el : env.elements)
            window.draw(el.sprite);
        drawPhysicSetting(window, Physical.gravity);
        drawPhysicSetting(window, Physical.wind);
        drawPhysicSetting(window, Physical.weight);
        drawPhysicSetting(window, Physical.friction);
        drawPhysicSetting(window, Physical.restitution);

        handelEvent(window, intro, Physical);


        if (resart)
        {
            for (element &el : env.elements)
                el.setPostion(sf::Vector2f(300.f, 100.f));
            resart = false;
        }

        for (const element &el : env.elements)
            std::cout << "env.el: (" << el.position.x << ", " << el.position.y << ")\n";
        window.display();
    }
    running = false;
    Force.join();
}

int main()
{
    OpenApp();
}

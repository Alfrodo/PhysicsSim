#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

#define CHAR_SIZE 24
#define TEXT_COLOR sf::Color::White
#define TEXT_STYLE sf::Text::Bold

class UIManager
{
    std::vector<sf::Drawable> uiElements;
    sf::Font font;
    sf::Text desc_gravity_source_mass;
    sf::Text val_gravity_source_mass;
    sf::Text desc_particle_speed;
    sf::Text val_particle_speed;

public:

	void initUI();
    void setMassText(std::string str) { val_gravity_source_mass.setString(str); }
    void setVelocityText(std::string str) { val_particle_speed.setString(str); }
    void renderUI(sf::RenderWindow& window);
};


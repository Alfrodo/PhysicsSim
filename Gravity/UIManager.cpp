#include "UIManager.h"



void UIManager::initUI()
{



    if (!font.loadFromFile("Fonts/ITCKRIST.TTF")) {
        std::cout << "Error loading fonts..." << std::endl;
    }
    desc_gravity_source_mass.setFont(font);
    desc_particle_speed.setFont(font);
    val_gravity_source_mass.setFont(font);
    val_particle_speed.setFont(font);

    desc_gravity_source_mass.setCharacterSize(CHAR_SIZE);
    desc_particle_speed.setCharacterSize(CHAR_SIZE);
    val_gravity_source_mass.setCharacterSize(CHAR_SIZE);
    val_particle_speed.setCharacterSize(CHAR_SIZE);

    desc_gravity_source_mass.setFillColor(TEXT_COLOR);
    desc_particle_speed.setFillColor(TEXT_COLOR);
    val_gravity_source_mass.setFillColor(TEXT_COLOR);
    val_particle_speed.setFillColor(TEXT_COLOR);

    desc_gravity_source_mass.setStyle(TEXT_STYLE);
    desc_particle_speed.setStyle(TEXT_STYLE);
    val_gravity_source_mass.setStyle(TEXT_STYLE);
    val_particle_speed.setStyle(TEXT_STYLE);

    desc_gravity_source_mass.setPosition(20, 20);
    desc_particle_speed.setPosition(20, 50);
    val_gravity_source_mass.setPosition(300, 20);
    val_particle_speed.setPosition(300, 50);



    desc_gravity_source_mass.setString("Gravity Source mass:");
    desc_particle_speed.setString("Particle speed:");

}


void UIManager::renderUI(sf::RenderWindow& window)
{
    window.draw(desc_gravity_source_mass);
    window.draw(desc_particle_speed);
    window.draw(val_gravity_source_mass);
    window.draw(val_particle_speed);
}

#pragma once
#include <SFML/Graphics.hpp>
#include "GravitySource.h"

class Particle : public SpaceObject
{
    sf::Vector2f vel;
    SpaceObjectType type;

public:
    Particle(float pos_x, float pos_y, float size, sf::Vector2f vel);
    Particle(float pos_x, float pos_y, float size, sf::Vector2f vel, sf::Color color);

    void updatePhysics(GravitySource& s);

    float getVelocity() { return sqrt(vel.x * vel.x + vel.y * vel.y); }

    void setColorToSpeed();

};
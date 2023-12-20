#pragma once
#include <SFML/Graphics.hpp>

class SpaceObject
{
protected:
    sf::Vector2f pos;
    float size;
    sf::CircleShape obj_shape;

public:
        SpaceObject(float pos_x, float pos_y, float size);

        void render(sf::RenderWindow& window);
        void setSize(float size);
        sf::Vector2f getPos() const { return pos; }
        float getSize() const { return size; }
};


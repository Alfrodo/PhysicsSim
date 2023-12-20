#include "GravitySource.h"


GravitySource::GravitySource(float pos_x, float pos_y, float size, float str) : SpaceObject(pos_x, pos_y, size)
{
    this->str = str;
    obj_shape.setFillColor(sf::Color::Yellow);
    
}




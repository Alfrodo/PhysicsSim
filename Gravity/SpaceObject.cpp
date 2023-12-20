#include "SpaceObject.h"


SpaceObject::SpaceObject(float pos_x, float pos_y, float size) {
    pos.x = pos_x;
    pos.y = pos_y;
    this->size = size;

    obj_shape.setPosition(pos);
    setSize(this->size);
    obj_shape.setOrigin(obj_shape.getRadius(), obj_shape.getRadius());
    
}

void SpaceObject::render(sf::RenderWindow& window)
{
    obj_shape.setPosition(pos);
    window.draw(obj_shape);
}

void SpaceObject::setSize(float size) {
    this->size = size;
    obj_shape.setRadius(this->size);

    //Center the shape to the source
    obj_shape.setOrigin(obj_shape.getRadius(), obj_shape.getRadius());
}

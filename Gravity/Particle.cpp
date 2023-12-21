#include "Particle.h"


    Particle::Particle(float pos_x, float pos_y, float size, sf::Vector2f vel) : SpaceObject(pos_x, pos_y, size)
    {
        this->vel = vel;
        obj_shape.setFillColor(sf::Color::Green);
        type = SpaceObjectType::PARTICLE;
    }



    void Particle::updatePhysics(GravitySource& s)
    {
        float dist_x = s.getPos().x - pos.x;
        float dist_y = s.getPos().y - pos.y;

        float dist = sqrt(dist_x * dist_x + dist_y * dist_y);

        float inv_dist = 1.f / dist;

        float norm_x = inv_dist * dist_x;
        float norm_y = inv_dist * dist_y;

        float inv_square_factor = inv_dist * inv_dist;

        float acc_x = norm_x * s.getStr() * inv_square_factor;
        float acc_y = norm_y * s.getStr() * inv_square_factor;

        vel.x += acc_x;
        vel.y += acc_y;

        pos += vel;
    }

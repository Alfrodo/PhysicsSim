#include "Particle.h"


    Particle::Particle(float pos_x, float pos_y, float size, sf::Vector2f vel) : SpaceObject(pos_x, pos_y, size)
    {
        this->vel = vel;
        obj_shape.setFillColor(sf::Color::White);
        type = SpaceObjectType::PARTICLE;
    }

    Particle::Particle(float pos_x, float pos_y, float size, sf::Vector2f vel, sf::Color color) : SpaceObject(pos_x, pos_y, size)
    {
        this->vel = vel;
        obj_shape.setFillColor(color);
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

        //Set color depending of speed
        setColorToSpeed();
    }

    void Particle::setColorToSpeed() {
        //Scale vel ~ 0-100 0 = White
        float clipped_velocity = getVelocity();
        if (clipped_velocity > 15.f) {
            clipped_velocity = 15.f;
        }



        int col_value = int((clipped_velocity / 15.f) * 255.f);
        col_value = (255 - col_value);
        obj_shape.setFillColor(sf::Color(255, col_value, col_value));
        
    }
#pragma once
#include <SFML/Graphics.hpp>
#include "SpaceObject.h"

class GravitySource : public SpaceObject
{
    float str;
    SpaceObjectType type;

public:
    GravitySource(float pos_x, float pos_y, float size, float str);

    float getStr()
    {
        return str;
    }

    void setStr(float delta) {
        if ((str + delta) > 0)
        {
            str += delta;
        }
        else
        {
            str = 0;
        }
    }

    void setPos(int x, int y)
    {
        pos.x = x;
        pos.y = y;
    }

};
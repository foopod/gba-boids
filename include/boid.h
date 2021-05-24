#ifndef BOID_H
#define BOID_H

#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

class Boid
{
    private:
        bn::sprite_ptr _sprite;
        bn::fixed_point _vel;
        bn::fixed _max_speed = 1;

    public:
        Boid(bn::fixed_point pos);
        bn::fixed_point pos();
        bn::fixed_point vel();
        void add_vel(bn::fixed_point addvel);
        void update();
};

#endif
#ifndef RULE_ALL_H
#define RULE_ALL_H

#include "rule.h"
#include "boid.h"

class AllRule
{
    private:
        const bn::fixed _separation_distance = 10;
        const bn::fixed _separation_force = 50;
        const bn::fixed _cohesion_force = 1000;
        const bn::fixed _bounding_force = 20;
        const bn::fixed _alignment_force = 50;
        const bn::fixed _alignment_reach = 15;

    public:
        void execute(bn::vector<Boid, 32>& boids, bn::vector<bn::fixed_point, 32>& velocities);
};

#endif

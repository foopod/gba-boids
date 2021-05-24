#ifndef RULE_SEPARATION_H
#define RULE_SEPARATION_H

#include "rule.h"
#include "boid.h"

class SeparationRule : public Rule
{
    private:
        const bn::fixed _separation_distance = 10;
        const bn::fixed _separation_force = 1;
        
        bn::fixed_point _current_pos;
        bn::fixed_point _jpos;

    public:
        void execute(bn::vector<Boid, 32>& boids);
};

#endif

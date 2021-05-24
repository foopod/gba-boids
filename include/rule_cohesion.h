#ifndef RULE_COHESION_H
#define RULE_COHESION_H

#include "rule.h"
#include "boid.h"

class CohesionRule : public Rule
{
    private:
        const bn::fixed _cohesion_force = 1000;

    public:
        void execute(bn::vector<Boid, 32>& boids);
};

#endif

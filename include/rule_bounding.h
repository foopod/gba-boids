#ifndef RULE_BOUNDING_H
#define RULE_BOUNDING_H

#include "rule.h"
#include "boid.h"

class BoundingRule : public Rule
{
    private:
        const bn::fixed _bounding_force = 20;

    public:
        void execute(bn::vector<Boid, 32>& boids);
};

#endif

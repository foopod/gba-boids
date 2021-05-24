#ifndef RULE_SCATTER_H
#define RULE_SCATTER_H

#include "rule.h"
#include "boid.h"

class ScatterRule : public Rule
{
    private:
        const bn::fixed _scatter_force = 100;

    public:
        void execute(bn::vector<Boid, 32>& boids);
};

#endif


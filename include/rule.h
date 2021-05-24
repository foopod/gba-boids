#ifndef RULE_H
#define RULE_H

#include "boid.h"
#include "bn_vector.h"

class Rule{
    public:
        virtual ~Rule(){};
        virtual void execute(bn::vector<Boid, 32>& boids) = 0;
};

#endif
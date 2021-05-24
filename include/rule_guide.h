#ifndef RULE_GUIDE_H
#define RULE_GUIDE_H

#include "rule.h"
#include "boid.h"

class GuideRule : public Rule
{
    private:
        const bn::fixed _guide_force = 1000;
    public:
        void execute(bn::vector<Boid, 32>& boids);
};

#endif

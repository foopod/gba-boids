#ifndef RULE_ALIGNMENT_H
#define RULE_ALIGNMENT_H

#include "rule.h"
#include "boid.h"

class AlignmentRule : public Rule
{
    private:
        const bn::fixed _alignment_force = 2;
        const bn::fixed _alignment_reach = 15;

        bn::fixed_point _current_pos;
        bn::fixed_point _jpos;

    public:
        void execute(bn::vector<Boid, 32>& boids);
};

#endif

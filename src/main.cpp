#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_camera_ptr.h"
#include "bn_random.h"
#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_string.h"
#include "bn_sprite_items_boid.h"

#include "boid.h"
#include "rule.h"
#include "rule_cohesion.h"
#include "rule_separation.h"
#include "rule_alignment.h"
#include "rule_guide.h"
#include "rule_bounding.h"
#include "rule_scatter.h"
#include "rule_all.h"

int main()
{
    bn::core::init();

    bn::random random;
    
    // bn::sprite_ptr sp = bn::sprite_items::boid.create_sprite(0, 0);

    //boids
    bn::vector<Boid, 32> boids = {};
    for( int i = 0; i < 20; i ++ ){
        boids.push_back(Boid(bn::fixed_point(int(random.get() % 32), int(random.get() % 32))));
    }

    bn::vector<bn::fixed_point, 32> velocities = {};
    

    CohesionRule rule1 = CohesionRule();
    SeparationRule rule2 = SeparationRule();
    AlignmentRule rule3 = AlignmentRule();
    GuideRule rule4 = GuideRule();
    BoundingRule rule5 = BoundingRule();

    ScatterRule scatterRule = ScatterRule();

    AllRule allRules = AllRule();


    bn::fixed max_cpu_usage;
    int counter = 1;


    while(true)
    {
        max_cpu_usage = bn::max(max_cpu_usage, bn::core::last_cpu_usage());
        --counter;
        if(! counter)
        {
            BN_LOG("cpu:" + bn::to_string<32>((max_cpu_usage * 100).right_shift_integer()));
            max_cpu_usage = 0;
            counter = 60;
        }

        rule1.execute(boids);
        rule2.execute(boids);
        rule3.execute(boids);
        rule5.execute(boids);
        if(bn::keypad::a_held()){
            scatterRule.execute(boids);
        }

        // allRules.execute(boids, velocities);

        for(Boid& boid : boids){
            boid.update();
        }
        bn::core::update();
    }
}

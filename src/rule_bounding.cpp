#include "rule_bounding.h"
#include "boid.h"
#include "bn_log.h"
#include "bn_math.h"

void BoundingRule::execute(bn::vector<Boid, 32>& boids_ptr){
    bn::vector<Boid, 32>* boids = &boids_ptr;

    //  for each boid
    for(int i = 0; i < boids->size(); i++){
        Boid boid = boids->at(i);
        if(boid.pos().x() < -80){
            boids->at(i).add_vel(bn::fixed_point(_bounding_force, 0));
        } else if(boid.pos().x() > 80){
            boids->at(i).add_vel(bn::fixed_point(-_bounding_force, 0));
        }

        if(boid.pos().y() < -50){
            boids->at(i).add_vel(bn::fixed_point(0, _bounding_force));
        } else if(boid.pos().y() > 50){
            boids->at(i).add_vel(bn::fixed_point(0, -_bounding_force));
        }
    }
}

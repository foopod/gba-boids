#include "rule_cohesion.h"
#include "boid.h"
#include "bn_log.h"

void CohesionRule::execute(bn::vector<Boid, 32>& boids){
    bn::vector<Boid, 32>* boids_ptr = &boids;

    //find centre of bird mass
    bn::fixed_point centre = bn::fixed_point(0,0);
    for(int i = 0; i < boids_ptr->size(); i++){
        centre += boids_ptr->at(i).pos();
    }

    centre/= boids_ptr->size();

    //apply to each boid
    for(int i = 0; i < boids_ptr->size(); i++){
        boids_ptr->at(i).add_vel((centre - boids_ptr->at(i).pos()) / _cohesion_force);
    }
    
}

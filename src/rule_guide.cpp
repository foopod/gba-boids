#include "rule_guide.h"
#include "boid.h"
#include "bn_log.h"
#include "bn_string.h"
#include "bn_math.h"

void GuideRule::execute(bn::vector<Boid, 32>& boids_ptr){
    bn::vector<Boid, 32>* boids = &boids_ptr;

    //  for each boid
    for(int i = 0; i < boids->size(); i++){
        bn::fixed_point pos = boids->at(i).pos();
        bn::fixed_point cv = (bn::fixed_point(0,0) - pos) / _guide_force;
        
        // BN_LOG("pos : " + bn::to_string<32>(pos.x()) + ", " + bn::to_string<32>(pos.y()));
        // BN_LOG("vel : " + bn::to_string<32>(cv.x()) + ", " + bn::to_string<32>(cv.y()));
        boids->at(i).add_vel(cv);
    }
}

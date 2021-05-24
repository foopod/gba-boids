#include "rule_separation.h"
#include "boid.h"
#include "bn_log.h"
#include "bn_math.h"

void SeparationRule::execute(bn::vector<Boid, 32>& boids_ptr){
    bn::vector<Boid, 32>* boids = &boids_ptr;

    //  for each boid
    for(int i = 0; i < boids->size(); i++){
        _current_pos = boids->at(i).pos();
        
        //for each other boid
        for(int j = 0; j < boids->size(); j++){
            if( j != i){
                _jpos = boids->at(j).pos();

                if(bn::abs(_current_pos.x() - _jpos.x()) < _separation_distance){
                    if(bn::abs(_current_pos.y() - _jpos.y()) < _separation_distance){
                        boids->at(i).add_vel((_current_pos - _jpos) / _separation_force);
                    }
                }
            }
        }
    }
}

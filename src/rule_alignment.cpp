#include "rule_alignment.h"
#include "boid.h"
#include "bn_log.h"
#include "bn_string.h"
#include "bn_math.h"

void AlignmentRule::execute(bn::vector<Boid, 32>& boids_ptr){
    bn::vector<Boid, 32>* boids = &boids_ptr;

    //  for each boid
    for(int i = 0; i < boids->size(); i++){
        _current_pos = boids->at(i).pos();

        //for each other boid
        for(int j = 0; j < boids->size(); j++){
            if( j != i){

                _jpos = boids->at(j).pos();

                if(bn::abs(_current_pos.x() - _jpos.x()) < _alignment_reach){
                    if(bn::abs(_current_pos.y() - _jpos.y()) < _alignment_reach){
                        boids->at(i).add_vel(boids->at(j).vel());
                    }
                }
            }
        }
    }
}

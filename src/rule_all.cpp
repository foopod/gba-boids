#include "rule_all.h"
#include "boid.h"
#include "bn_log.h"
#include "bn_string.h"
#include "bn_math.h"

void AllRule::execute(bn::vector<Boid, 32>& boids_ptr, bn::vector<bn::fixed_point, 32>& velocities_ptr){
    bn::vector<Boid, 32>* boids = &boids_ptr;
    bn::vector<bn::fixed_point, 32>* velocities = &velocities_ptr;
    velocities_ptr.clear();

    bn::fixed_point centre = bn::fixed_point(0,0);
    bn::fixed_point velocity = bn::fixed_point(0,0);

    bn::fixed dx = 0;
    bn::fixed dy = 0;

    bn::fixed_point jpos;

    int size = boids->size();

    for(int i = 0; i < size; i++){
        centre += boids->at(i).pos();
    }
    centre/= size;

    //  for each boid
    for(int i = 0; i < size; i++){
        bn::fixed_point current_pos = boids->at(i).pos();

        //cohesion
        velocity += (centre - current_pos) / _cohesion_force;

        //for each other boid
        for(int j = 0; j < size; j++){
            if( j != i){
                jpos = boids->at(j).pos();

                dx = bn::abs(current_pos.x() - jpos.x());
                dy = bn::abs(current_pos.y() - jpos.y());
                if(dx < _alignment_reach){
                    if(dy < _alignment_reach){
                        //alignment
                        velocity += boids->at(j).vel()/_alignment_force;
                        if(dx < _separation_distance){
                            if(dy < _separation_distance){
                                //separation
                                velocity += (current_pos - jpos) / _separation_force;
                            }
                        }
                    }
                }
            }
        }

        //bounding
        if(boids->at(i).pos().x() < -120){
            velocity += bn::fixed_point(_bounding_force, 0);
        } else if(boids->at(i).pos().x() > 120){
            velocity += bn::fixed_point(-_bounding_force, 0);
        }
        if(boids->at(i).pos().y() < -70){
            velocity += bn::fixed_point(0, _bounding_force);
        } else if(boids->at(i).pos().y() > 70){
            velocity += bn::fixed_point(0, -_bounding_force);
        }
        velocities->push_back(velocity);
    }

    for(int i = 0; i < size; i++){
        boids->at(i).add_vel(velocities->at(i));
    }
}

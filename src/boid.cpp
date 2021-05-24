#include "boid.h"
#include "bn_math.h"
#include "bn_log.h"
#include "bn_string.h"

#include "bn_sprite_items_boid.h"

Boid::Boid(bn::fixed_point pos)
    : _sprite(bn::sprite_items::boid.create_sprite(pos.x(), pos.y())), 
      _vel(bn::fixed_point(0,0))
{
    // _sprite.set_horizontal_scale(0.5);
    // _sprite.set_vertical_scale(0.5);
}

bn::fixed_point Boid::pos(){
    return _sprite.position();
}

bn::fixed_point Boid::vel(){
    return _vel;
}

void Boid::add_vel(bn::fixed_point addvel){
    _vel += addvel;
}

void Boid::update(){
    bn::fixed_point curr = _sprite.position();

    //clamp velocity
    if(bn::abs(_vel.x()) > _max_speed && bn::abs(_vel.x()) > bn::abs(_vel.y())){
        bn::fixed m = bn::abs(_vel.x())/_max_speed;
        _vel.set_x(_vel.x()/m);
        _vel.set_y(_vel.y()/m);
    }
    if(bn::abs(_vel.y()) > _max_speed && bn::abs(_vel.y()) > bn::abs(_vel.x())){
        bn::fixed m = bn::abs(_vel.y())/_max_speed;
        _vel.set_x(_vel.x()/m);
        _vel.set_y(_vel.y()/m);
    }

    //apply velocity
    _sprite.set_position(curr + _vel);

    //apply rotation
    // bn::fixed rot;
    // if(_vel.y() > 0){
    //     rot = bn::degrees_atan2((_vel.y()*100).integer(), (_vel.x()*100).integer()).integer();
    // } else {
    //     rot = bn::degrees_atan2((_vel.y()*100).integer(), (_vel.x()*100).integer()).integer() - 180;
    // }
     
    // if(rot < 0){
    //     rot+= 360;
    // } else if(rot > 360){
    //     rot-= 360;
    // }
    // _sprite.set_rotation_angle(rot);
}
#include <Novice.h>
#include "Bullet.h"

Bullet::Bullet() {
	pos_ = {};
	radius_ = 10.0f;
	speed_ = 10.0f;
	isShot_ = false;
};


void Bullet::Init(float x, float y) {
	pos_ = { x,y };
	radius_ = 10.0f;
	speed_ = 10.0f;
	isShot_ = true;
};


void Bullet::Update() {
	pos_.y -= speed_ ;
}


void Bullet::Render() {
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0, 0x6622CCff, kFillModeSolid);
}
void Bullet::ShotOnOff(bool OnOff)
{
	if(OnOff){isShot_ = true;}
	else if(!OnOff){isShot_ = false;}
}
;
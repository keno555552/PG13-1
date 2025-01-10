#include "Enemy.h"

#pragma region Enemy
Enemy::Enemy()
{
	pos_ = {};
	speed_ = 10.0f;
	radius_ = 20.0f;
}

void Enemy::init(float x, float y)
{
	pos_ = { x,y };
}

void Enemy::Update(Player* player)
{
	if (isAlive_) {
		///移動
		pos_.x += speed_;
		if (pos_.x + radius_ > 1280) {
			speed_ *= -1;
			pos_.x = 1280 - radius_;
		}
		if (pos_.x - radius_ < 0) {
			speed_ *= -1;
			pos_.x = 0 + radius_;
		}

		///当たり判定
		for (int i = 0; i < 10; i++) {
			if (player->GetBullets(i)->ShotOnOff()) {
				float LX = pos_.x - player->GetBullets(i)->GetPos().x;
				float LY = pos_.y - player->GetBullets(i)->GetPos().y;
				float LA = radius_ + player->GetBullets(i)->GetRadius();

				if (LA >= sqrtf(powf(LX, 2) + powf(LY, 2))) {
					EnemyHitCount++;
					player->GetBullets(i)->ShotOnOff(false);
				}
			}
		}
	}

	///EnemyHitCountに消えるのかを判断
	if (EnemyHitCount > 0) {
		isAlive_ = false;
	} else {
		isAlive_ = true;
	}
}

void Enemy::Render()
{
	if (isAlive_) {
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
}

#pragma endregion


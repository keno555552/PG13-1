#include "Player.h"
#include <Novice.h>
#include <math.h> 

Player::Player() {
	for (int i = 0; i < 10; i++) {
		bullet_[i] = new(Bullet);
	}
	pos_ = {};
	vector_ = {};
	radius_ = {};
	speed_ = {};
	coolTimer_ = {};
};

Player::~Player() {
	for (int i = 0; i < 10; i++) {
		delete bullet_[i];
	}
};


void Player::Init(const int posX, const int posY) {

	pos_ = { float(posX) ,float(posY) };
	vector_ = {};
	radius_ = 30.0f;
	speed_ = 5.0f;
	coolTimer_ = { 0,10 };
}

void Player::Updata(const char* key) {

	///////////////////////////////////////////////////////////移動
	Vector2 vectorHandle = {};
	float vectorDiagonal = {};

	vector_.x = 0.0f;
	vector_.y = 0.0f;

	///上下左右vector計算
	if (key[DIK_UP] || key[DIK_W]) { vector_.y -= 1.0f; }
	if (key[DIK_DOWN] || key[DIK_S]) { vector_.y += 1.0f; }
	if (key[DIK_LEFT] || key[DIK_A]) { vector_.x -= 1.0f; }
	if (key[DIK_RIGHT] || key[DIK_D]) { vector_.x += 1.0f; }

	///シャガミ移動処理
	vectorDiagonal = sqrtf((float)powf(vector_.x, 2.0f) + (float)powf(vector_.y, 2.0f));
	vectorHandle.x = vector_.x;
	vectorHandle.y = vector_.y;

	if (vectorDiagonal != 0.0f) {
		vectorHandle.x = vector_.x / vectorDiagonal;
		vectorHandle.y = vector_.y / vectorDiagonal;
	}

	///移動処理
	if ((vectorHandle.x != 0) || (vectorHandle.y != 0)) {
		pos_.x += vectorHandle.x * speed_;
		pos_.y += vectorHandle.y * speed_;
	}

	///////////////////////////////////////////////////////////弾丸

	///弾丸のクールダウン計算
	if (coolTimer_.clock > 0) {
		coolTimer_.clock--;
	}

	///ボタンを押すとき
	if (key[DIK_SPACE]) {
		///クールダウンが0に
		if (coolTimer_.clock == 0) {
			///弾丸を円を回って12ご配置
			for (int i = 0; i < 10; i++) {
				if (!bullet_[i]->ShotOnOff()) {
					bullet_[i]->Init(pos_.x, pos_.y);
					break;
				}
			}
			///クールダウンをリセット
			coolTimer_.clock = coolTimer_.time;
		}
	}

	///弾丸の更新
	for (int i = 0; i < 10; i++) {
		if (bullet_[i]->ShotOnOff()) {
			bullet_[i]->Update();
		}
		if (bullet_[i]->GetPos().y < -10 || bullet_[i]->GetPos().y >1280) {
			bullet_[i]->ShotOnOff(false);
		}
	}


};

void Player::Render(){
	///弾丸描写
	for (int i = 0; i < 10; i++) {
		if (bullet_[i]->ShotOnOff()) {
			bullet_[i]->Render();
		}
	}
	///プレイヤー描写
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), (int)radius_, (int)radius_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
}

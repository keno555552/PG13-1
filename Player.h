#pragma once
#include <Vector2.h>
#include <Timer.h>
//#include <vector>
#include "Bullet.h"

class Player{
public:

	///メンバー関数
	Player();
	~Player();

	/// <summary>
	/// Playerを初期化する
	/// </summary>
	/// <param name="posX"></param>
	/// <param name="posY"></param>
	void Init(const int posX, const int posY);


	/// <summary>
	/// Playerのすべでの処理
	/// </summary>
	/// <param name="key">keys</param>
	void Updata(const char* key);

	/// <summary>
	/// Playerの描画処理
	/// </summary>
	void Render();

	/// <summary>
	/// Bulletのポインターを渡す
	/// </summary>
	/// <param name="Num">弾丸の番号</param>
	/// <returns>Bulletのポインター</returns>
	Bullet* GetBullets(const int Num) { return bullet_[Num]; }

private:
	///メンバー変数
	Vector2 pos_;
	Vector2 vector_;
	float radius_;
	float speed_;
	Bullet * bullet_[10];
	Timer coolTimer_;
};


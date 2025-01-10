#pragma once
#include <Vector2.h>
#include <Timer.h>
#include <Novice.h>
#include<vector>

class Bullet{
public:

	Bullet();

	///メンバー関数
	
	/// <summary>
	/// Playerを初期化する
	/// </summary>
	void Init(float x,float y);

	/// <summary>
	/// 弾丸の移動処理
	/// </summary>
	void Update();

	/// <summary>
	/// 弾丸を描画する
	/// </summary>
	void Render();

	/// <summary>
	/// 弾丸の pos構造体を引用する
	/// </summary>
	/// <returns>Vector pos_</returns>
	Vector2 GetPos() { return pos_; }

	/// <summary>
	/// 弾丸の半径を引用する
	/// </summary>
	/// <returns>radius_</returns>
	float GetRadius() { return radius_; }

	/// <summary>
	/// isShot_を falseにする
	/// </summary>
	void ShotOnOff(bool OnOff);	
	
	/// <summary>
	/// isShot_を返す
	/// </summary>
	/// <returns>isShot_</returns>
	bool ShotOnOff() { return isShot_; }

private:
	///メンバー変数
	Vector2 pos_;
	float radius_;
	float speed_;
	bool isShot_;
};


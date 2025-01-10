#pragma once
#include <Vector2.h>
#include <Novice.h>
#include <Player.h>
#include <Math.h>


class Enemy
{
public:
	static int EnemyHitCount;

	Enemy();
	void init(float x, float y);
	void Update(Player* player);
	void Render();

private:
	Vector2 pos_;
	float speed_;
	float radius_;
	bool isAlive_;
};
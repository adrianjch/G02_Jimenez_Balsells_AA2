#pragma once
#include "Utils.h"
#include <string>
#include <ctime>

class Enemy {
public:
	enum class EnemyState { NORMAL, SCARED, DEAD };
protected:
	Vec2 pixelPos;
	Vec2 cellPos;
	Vec2 initialPos;
	EnemyState state;
	clock_t deadTimer;

public:
	Enemy();
	Vec2 GetPixelPos();
	Vec2 GetMapPos();
	void SetInitialPos(Vec2);
	void Dead();
};
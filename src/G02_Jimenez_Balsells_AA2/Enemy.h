#pragma once
#include "Types.h"
#include "Renderer.h"
#include <string>
#include <ctime>

class Enemy {
public:
	enum class EnemyState { NORMAL, SCARED, DEAD };
protected:
	Vec2 pixelPos;
	Vec2 initialPos;
	EnemyState state;
	clock_t deadTimer;
public:
	Enemy();
	Vec2 GetInitialPos() const;
	Vec2 GetPixelPos() const;
	void SetInitialPos(const Vec2 &);
	void SetPixelPos(const Vec2 &);
	void Dead();//
};
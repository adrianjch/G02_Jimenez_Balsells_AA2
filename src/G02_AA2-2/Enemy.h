#pragma once
#include "Types.h"
#include "Renderer.h"
#include <string>
#include <ctime>

class Enemy {
public:
	enum class State { NORMAL, SCARED, DEAD };
protected:
	Vec2 pixelPos;
	Vec2 initialPos;
	State state;
	float deadTimer;
	int spriteNumber;
	int frameCounter;
	const int MAX_FRAME = 5;
public:
	Enemy();
	Vec2 GetInitialPos() const;
	Vec2 GetPixelPos() const;
	State GetState() const;
	void SetInitialPos(const Vec2 &);
	void SetPixelPos(const Vec2 &);
	void SetState(const State &);
	virtual void Reset() = 0;
};
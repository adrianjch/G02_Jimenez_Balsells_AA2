#pragma once
#include "Enemy.h"

class Blinky : public Enemy {
public:
	Blinky();
	void Update(**Cell);
	void Move(**Cell, Vec2);
	void Draw(std::string);
};
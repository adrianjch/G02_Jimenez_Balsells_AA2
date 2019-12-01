#pragma once
#include "Enemy.h"

class Inky : public Enemy {
public:
	Inky();
	void Update(**Cell);
	void Move(**Cell, Vec2);
	void Draw(std::string);
};
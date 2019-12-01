#pragma once
#include "Enemy.h"


class Clyde : public Enemy {
public:
	Clyde();
	void Update(**Cell);
	void Move(**Cell, Vec2);
	void Draw(std::string);
};
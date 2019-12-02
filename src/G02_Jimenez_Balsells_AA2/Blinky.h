#pragma once
#include "Enemy.h"
#include "Map.h"

class Blinky : public Enemy {
public:
	Blinky();
	void Update(Map::Cell**);
	void Move(Map::Cell**, Vec2);
	void Draw(std::string);
};
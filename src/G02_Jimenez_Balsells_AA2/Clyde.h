#pragma once
#include "Enemy.h"
#include "Map.h"

class Clyde : public Enemy {
public:
	Clyde();
	void Update(Map::Cell**);
	void Move(Map::Cell**, Vec2);
	void Draw(std::string);
};
#pragma once
#include "Enemy.h"
#include "Map.h"

class Inky : public Enemy {
public:
	Inky();
	void Update(Map::Cell** map);
	void Move(Map::Cell** map, Vec2);
	void Draw();
};
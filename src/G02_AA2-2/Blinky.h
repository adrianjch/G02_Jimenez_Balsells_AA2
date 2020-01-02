#pragma once
#include "Enemy.h"
#include "Map.h"

class Blinky : public Enemy {
private:
	Movement actualMovement;
public:
	Blinky();
	void Update(const Map &);
	void Move(const Map &);
	void Draw() const;
	void Reset();
};
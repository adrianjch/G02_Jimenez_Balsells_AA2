#pragma once
#include "Enemy.h"
#include "Map.h"
#include "Types.h"

class Inky : public Enemy {
private:
	Movement actualMovement;
	Movement futureMovement;
public:
	Inky();
	void Update(const Input &, Map&);
	void Move(Map &);
	void Draw();
};
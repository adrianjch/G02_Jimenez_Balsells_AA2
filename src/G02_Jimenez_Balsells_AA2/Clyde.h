#pragma once
#include "Enemy.h"
#include "Map.h"
#include "Types.h"

class Clyde : public Enemy {
private:
	Movement actualMovement;
	Movement futureMovement;
public:
	Clyde();
	void Update(const Input &, Map&);
	void Move(Map &);
	void Draw();
};
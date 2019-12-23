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
	void Update(const Input &, const Map &);
	void Move(const Map &);
	void Draw() const;
	void Reset();
};
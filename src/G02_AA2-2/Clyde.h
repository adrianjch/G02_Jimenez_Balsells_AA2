#pragma once
#include "Enemy.h"
#include "Map.h"
#include "Types.h"

class Clyde : public Enemy {
private:
	Movement actualMovement;
	Movement futureMovement;
	int spriteNumber;
	int frameCounter;
	const int MAX_FRAME = 5;
public:
	Clyde();
	void Update(const Input &, const Map &);
	void Move(const Map &);
	void Draw() const;
	void Reset();
};
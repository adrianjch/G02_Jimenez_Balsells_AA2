#pragma once
#include "Types.h"
#include <string>

class Fruit {
public:
	enum class FruitType {ORANGE, SRTRAWBERRY, CHERRY };
private:
	Vec2 initialPos;
	FruitType type;
public:
	Fruit();
	Vec2 GetInitialPos() const;
	FruitType GetType() const;
	void SetInitialPos(const Vec2 &);
	void Update();//
	void Draw() const;
};
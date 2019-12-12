#pragma once
#include "Types.h"
#include <string>
#include "Renderer.h"

class Fruit {
public:
	enum class FruitType {ORANGE, SRTRAWBERRY, CHERRY, COUNT };
private:
	Vec2 initialPos;
	FruitType type;
public:
	Fruit(const Vec2 &);
	Vec2 GetInitialPos() const;
	FruitType GetType() const;
	void SetInitialPos(const Vec2 &);
	void Update();//
	void Draw() const;
};
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
	float timeCounter; // timer var
	float timeToSpawn; // ammount of seconds the timer has to reach to appear
	bool active;
public:
	Fruit();
	Vec2 GetInitialPos() const;
	FruitType GetType() const;
	bool IsActive() const;
	void Destroy();
	void SetInitialPos(const Vec2 &);
	void Update(const Vec2 &);
	void Draw() const;
};
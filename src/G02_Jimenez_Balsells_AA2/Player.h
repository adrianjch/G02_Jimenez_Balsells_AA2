#pragma once
#include "Types.h"
#include "Map.h"
#include <ctime>
#include <string>

class Player {
private:
	Vec2 pixelPos;
	Vec2 cellPos;
	Vec2 initialPos;
	int score;
	int lives;
	bool isEmpowered;
	clock_t empoweredTimer;
public:
	Player();
	Vec2 GetPixelPos();
	Vec2 GetMapPos();
	int GetScore();
	int GetLives();
	bool IsEmpowered();
	void SetInitialPos(Vec2);
	void SetScore(int);
	void SetLives(int);
	void SetEmpowered(bool);
	void Update(const Input &, Map::Cell**);
	void Move(Map::Cell**, Vec2);
	void Draw(std::string);
	void Dead();
};

#pragma once
#include "Types.h"
#include "Map.h"
#include "Renderer.h"
#include <ctime>
#include <string>

class Player {
private:
	enum class Movement { UP, DOWN, LEFT, RIGHT };
	Vec2 pixelPos;
	Vec2 cellPos;
	Vec2 initialPos;
	int score;
	int lives;
	bool isEmpowered;
	Movement actualMovement;
	Movement futureMovement;
	clock_t empoweredTimer;
	Renderer* renderer;
public:
	Player();
	Vec2 GetInitialPos();
	Vec2 GetPixelPos();
	Vec2 GetMapPos();
	int GetScore();
	int GetLives();
	bool IsEmpowered();
	void SetInitialPos(Vec2);
	void SetScore(int);
	void SetLives(int);
	void SetEmpowered(bool);
	void Update(const Input &, Map&);
	void Move(Map::Cell**, Vec2);
	void Draw();
	void Dead();
};

#pragma once
#include "Types.h"
#include "Map.h"
#include "Renderer.h"
#include "Music.h"
#include <ctime>
#include <string>

class Player {
public:
	enum class State { RESET, DEAD, NORMAL, POWER };
private:
	State state;
	Vec2 pixelPos;
	Vec2 initialPos;
	int score;
	int lives;
	Movement actualMovement;
	Movement futureMovement;
	clock_t empoweredTimer;
	clock_t deadTimer;
	int spriteNumber;
	int frameCounter;
	const int MAX_FRAME_NORMAL = 4;
	const int MAX_FRAME_DEAD = 5;
public:
	Player();
	Vec2 GetInitialPos() const;
	Vec2 GetPixelPos() const;
	int GetScore() const;
	int GetLives() const;
	State GetState() const;
	void SetInitialPos(const Vec2 &);
	void SetScore(const int &);
	void SetLives(const int &);
	void SetState(const State &);
	void Update(const Input &, Map &);//
	void Move(const Map &);
	void Draw() const;
	void Reset();
	void Dead();//
};

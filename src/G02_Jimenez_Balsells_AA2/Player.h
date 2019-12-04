#pragma once
#include "Types.h"
#include "Map.h"
#include "Renderer.h"
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
	Movement actualMovement;
	Movement futureMovement;
	clock_t empoweredTimer;
	Renderer* renderer;
public:
	Player();
	Vec2 GetInitialPos() const;
	Vec2 GetPixelPos() const;
	Vec2 GetMapPos() const;
	int GetScore() const;
	int GetLives() const;
	bool IsEmpowered() const;
	void SetInitialPos(const Vec2 &);
	void SetScore(const int &);
	void SetLives(const int &);
	void SetEmpowered(const bool &);
	void Update(const Input &, Map &);//
	void Move(Map &);//
	void Draw() const;
	void Dead();//
};

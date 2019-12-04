#pragma once
#include "Types.h"
#include "Renderer.h"
#include <ctime>
#include <string>

class Map {
public:
	enum class Cell{NONE, POINT, POWER_UP, WALL};
private:
	Cell **map;
	int numColumns;
	int numRows;
	clock_t fruitTimer;
	Renderer *renderer;
	int coinCounter;
public:
	Map();
	Cell GetCell(Vec2);
	void SetSize(Vec2);
	Vec2 GetSize();
	int GetCoinCounter();
	void SetCoinCounter(int);
	void SetCell(Vec2, Cell);
	void Update();
	void Draw();
};
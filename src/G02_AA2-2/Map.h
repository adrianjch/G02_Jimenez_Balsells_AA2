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
	int coinCounter;
public:
	Map();
	Cell GetCell(const Vec2 &) const;
	Vec2 GetSize() const;
	int GetCoinCounter() const;
	void SetCell(const Vec2 &, const Cell &) const;
	void SetSize(const Vec2 &);
	void SetCoinCounter(const int &);
	void Update();//
	void Draw() const;
};
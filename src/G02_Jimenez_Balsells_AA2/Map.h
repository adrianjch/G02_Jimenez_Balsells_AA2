#pragma once
#include "Types.h"
#include <ctime>
#include <string>

class Map {
public:
	enum class Cell{NONE, POINT, POWER_UP, WALL};
private:
	int windowWidth;
	int windowHeight;
	Cell **map;
	int numColumns;
	int numRows;
	clock_t fruitTimer;
public:
	Map();
	void SetCell(Vec2, Cell);
	void Update();
	void Draw(std::string);

};
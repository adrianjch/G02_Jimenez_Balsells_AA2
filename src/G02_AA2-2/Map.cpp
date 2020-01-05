#include "Map.h"

Map::Map() {

}

Map::Cell Map::GetCell(const Vec2 &pos) const{
	return map[pos.x][pos.y];
}

Vec2 Map::GetSize() const{
	return { numColumns, numRows };
}

int Map::GetCoinCounter() const{
	return coinCounter;
}

void Map::SetCell(const Vec2 &pos, const Cell &type) const{
	map[pos.x][pos.y] = type;
}

void Map::SetSize(const Vec2 &pos) {
	numColumns = pos.x;
	numRows = pos.y;
	// Create map
	map = new Cell*[numRows];
	for (int x = 0; x < numColumns; x++) {
		map[x] = new Cell[numRows];
		for (int y = 0; y < numRows; y++)
			map[x][y] = Cell::POINT;
	}
}

void Map::SetCoinCounter(const int &coins) {
	coinCounter = coins;
}

void Map::Draw() const{
	for (int y = 0; y < numRows; y++) {
		for (int x = 0; x < numColumns; x++) {
			switch (map[x][y]) {
				case Cell::WALL:
					Renderer::Instance()->PushSprite("spritesheet", { 512, 768, 128, 128 }, { x*35, y*35, 35, 35 });
					break;
				case Cell::POINT:
					Renderer::Instance()->PushSprite("spritesheet", { 640, 768, 128, 128 }, { x*35, y*35, 35, 35 });
					break;
				case Cell::POWER_UP:
					Renderer::Instance()->PushSprite("spritesheet", { 768, 768, 128, 128 }, { x*35, y*35, 35, 35 });
					break;
				default:
					break;
			}
		}
	}
}
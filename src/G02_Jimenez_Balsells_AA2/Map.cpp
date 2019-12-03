#include "Map.h"

Map::Map() {
	renderer = renderer->Instance();
}

Map::Cell Map::GetCell(Vec2 pos) {
	return map[pos.x][pos.y];
}

void Map::SetSize(Vec2 pos) {
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

void Map::SetCell(Vec2 pos, Cell type) {
	map[pos.x][pos.y] = type;
}

void Map::Update() {

}

void Map::Draw() {
	for (int y = 0; y < numRows; y++) {
		for (int x = 0; x < numColumns; x++) {
			switch (map[x][y]) {
				case Cell::WALL:
					renderer->PushSprite("spritesheet", { 512, 768, 128, 128 }, { x*35, y*35, 35, 35 });
					break;
				case Cell::POINT:
					renderer->PushSprite("spritesheet", { 640, 768, 128, 128 }, { x*35, y*35, 35, 35 });
					break;
				case Cell::POWER_UP:
					renderer->PushSprite("spritesheet", { 768, 768, 128, 128 }, { x * 35, y * 35, 35, 35 });
					break;
				default:
					break;
			}
		}
	}
}
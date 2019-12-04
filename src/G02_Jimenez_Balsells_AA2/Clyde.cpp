#pragma once
#include "Clyde.h"

Clyde::Clyde() {
	actualMovement = futureMovement = Movement::RIGHT;
	spriteNumber = 4;
	frameCounter = 0;
}

void Clyde::Update(const Input &input, const Map &map) {
	if (input.keyDown.at(Input::Key::W) || input.keyDown.at(Input::Key::UP))
		futureMovement = Movement::DOWN;
	else if (input.keyDown.at(Input::Key::A) || input.keyDown.at(Input::Key::LEFT))
		futureMovement = Movement::RIGHT;
	else if (input.keyDown.at(Input::Key::S) || input.keyDown.at(Input::Key::DOWN))
		futureMovement = Movement::UP;
	else if (input.keyDown.at(Input::Key::D) || input.keyDown.at(Input::Key::RIGHT))
		futureMovement = Movement::LEFT;

	Move(map);

	frameCounter++;
}

void Clyde::Move(const Map &map) {
	switch (actualMovement) {
	case Movement::UP:
		switch (futureMovement) {
		case Movement::DOWN:
			actualMovement = Movement::DOWN;
			break;
		case Movement::LEFT:
			if (pixelPos.y % CELL_SIZE == 0 && map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::LEFT;
			}
			break;
		case Movement::RIGHT:
			if (pixelPos.y % CELL_SIZE == 0 && map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::RIGHT;
			}
			break;
		}
		break;
	case Movement::DOWN:
		switch (futureMovement) {
		case Movement::UP:
			actualMovement = Movement::UP;
			break;
		case Movement::LEFT:
			if (pixelPos.y % CELL_SIZE == 0 && map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::LEFT;
			}
			break;
		case Movement::RIGHT:
			if (pixelPos.y % CELL_SIZE == 0 && map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::RIGHT;
			}
			break;
		}
		break;
	case Movement::LEFT:
		switch (futureMovement) {
		case Movement::UP:
			if (pixelPos.x % CELL_SIZE == 0 && map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::UP;
			}
			break;
		case Movement::DOWN:
			if (pixelPos.x % CELL_SIZE == 0 && map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::DOWN;
			}
			break;
		case Movement::RIGHT:
			actualMovement = Movement::RIGHT;
			break;
		}
		break;
	case Movement::RIGHT:
		switch (futureMovement) {
		case Movement::UP:
			if (pixelPos.x % CELL_SIZE == 0 && map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::UP;
			}
			break;
		case Movement::DOWN:
			if (pixelPos.x % CELL_SIZE == 0 && map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::DOWN;
			}
			break;
		case Movement::LEFT:
			actualMovement = Movement::LEFT;
			break;
		}
		break;
	}

	switch (actualMovement) {
	case Movement::UP:
		if (map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL)
			pixelPos.y -= 1;
		if (frameCounter >= MAX_FRAME) {
			if (spriteNumber == 0)
				spriteNumber = 1;
			else
				spriteNumber = 0;
			frameCounter = 0;
		}
		break;
	case Movement::DOWN:
		if (map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL)
			pixelPos.y += 1;
		if (frameCounter >= MAX_FRAME) {
			if (spriteNumber == 2)
				spriteNumber = 3;
			else
				spriteNumber = 2;
			frameCounter = 0;
		}
		break;
	case Movement::LEFT:
		if (map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL)
			pixelPos.x -= 1;
		if (frameCounter >= MAX_FRAME) {
			if (spriteNumber == 6)
				spriteNumber = 7;
			else
				spriteNumber = 6;
			frameCounter = 0;
		}
		break;
	case Movement::RIGHT:
		if (map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) 
			pixelPos.x += 1;
		if (frameCounter >= MAX_FRAME) {
			if (spriteNumber == 4)
				spriteNumber = 5;
			else
				spriteNumber = 4;
			frameCounter = 0;
		}
		break;
	}

	if (pixelPos.x <= -CELL_SIZE)
		pixelPos.x = 699;
	else if (pixelPos.x >= 700)
		pixelPos.x = -CELL_SIZE + 1;

	if (pixelPos.y <= -CELL_SIZE)
		pixelPos.y = 699;
	else if (pixelPos.y >= 700)
		pixelPos.y = -CELL_SIZE + 1;
}

void Clyde::Draw() const{
	Renderer::Instance()->PushSprite("spritesheet", { spriteNumber*128, 384, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
}
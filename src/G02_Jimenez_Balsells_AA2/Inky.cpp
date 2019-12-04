#pragma once
#include "Inky.h"

Inky::Inky() {
	actualMovement = futureMovement = Movement::LEFT;
}

void Inky::Update(const Input &input, Map &map) {
	if (input.keyDown.at(Input::Key::W) || input.keyDown.at(Input::Key::UP))
		futureMovement = Movement::UP;
	else if (input.keyDown.at(Input::Key::A) || input.keyDown.at(Input::Key::LEFT))
		futureMovement = Movement::LEFT;
	else if (input.keyDown.at(Input::Key::S) || input.keyDown.at(Input::Key::DOWN))
		futureMovement = Movement::DOWN;
	else if (input.keyDown.at(Input::Key::D) || input.keyDown.at(Input::Key::RIGHT))
		futureMovement = Movement::RIGHT;

	Move(map);
}

void Inky::Move(Map &map) {
	switch (actualMovement) {
	case Movement::UP:
		switch (futureMovement) {
		case Movement::DOWN:
			actualMovement = Movement::DOWN;
			break;
		case Movement::LEFT:
			if (pixelPos.y % 35 == 0 && map.GetCell({ ((700 + pixelPos.x - 1) % 700) / 35, pixelPos.y / 35 }) != Map::Cell::WALL) {
				actualMovement = Movement::LEFT;
			}
			break;
		case Movement::RIGHT:
			if (pixelPos.y % 35 == 0 && map.GetCell({ (pixelPos.x + 35 % 700) / 35, pixelPos.y / 35 }) != Map::Cell::WALL) {
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
			if (pixelPos.y % 35 == 0 && map.GetCell({ ((700 + pixelPos.x - 1) % 700) / 35, pixelPos.y / 35 }) != Map::Cell::WALL) {
				actualMovement = Movement::LEFT;
			}
			break;
		case Movement::RIGHT:
			if (pixelPos.y % 35 == 0 && map.GetCell({ (pixelPos.x + 35 % 700) / 35, pixelPos.y / 35 }) != Map::Cell::WALL) {
				actualMovement = Movement::RIGHT;
			}
			break;
		}
		break;
	case Movement::LEFT:
		switch (futureMovement) {
		case Movement::UP:
			if (pixelPos.x % 35 == 0 && map.GetCell({ pixelPos.x / 35, ((700 + pixelPos.y - 1) % 700) / 35 }) != Map::Cell::WALL) {
				actualMovement = Movement::UP;
			}
			break;
		case Movement::DOWN:
			if (pixelPos.x % 35 == 0 && map.GetCell({ pixelPos.x / 35, (pixelPos.y + 35 % 700) / 35 }) != Map::Cell::WALL) {
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
			if (pixelPos.x % 35 == 0 && map.GetCell({ pixelPos.x / 35, ((700 + pixelPos.y - 1) % 700) / 35 }) != Map::Cell::WALL) {
				actualMovement = Movement::UP;
			}
			break;
		case Movement::DOWN:
			if (pixelPos.x % 35 == 0 && map.GetCell({ pixelPos.x / 35, (pixelPos.y + 35 % 700) / 35 }) != Map::Cell::WALL) {
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
		if (map.GetCell({ pixelPos.x / 35, ((700 + pixelPos.y - 1) % 700) / 35 }) != Map::Cell::WALL)
			pixelPos.y -= 1;
		break;
	case Movement::DOWN:
		if (map.GetCell({ pixelPos.x / 35, (pixelPos.y + 35 % 700) / 35 }) != Map::Cell::WALL)
			pixelPos.y += 1;
		break;
	case Movement::LEFT:
		if (map.GetCell({ ((700 + pixelPos.x - 1) % 700) / 35, pixelPos.y / 35 }) != Map::Cell::WALL)
			pixelPos.x -= 1;
		break;
	case Movement::RIGHT:
		if (map.GetCell({ (pixelPos.x + 35 % 700) / 35, pixelPos.y / 35 }) != Map::Cell::WALL)
			pixelPos.x += 1;
		break;
	}
	pixelPos.x = (665 + pixelPos.x) % 665;
	pixelPos.y = (665 + pixelPos.y) % 665;
}

void Inky::Draw() {
	renderer->PushSprite("spritesheet", { 0, 256, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
}
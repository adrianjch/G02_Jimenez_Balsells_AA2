#pragma once
#include "Player.h"

Player::Player() {
	renderer = renderer->Instance();
	actualMovement = futureMovement = Movement::LEFT;
}

Vec2 Player::GetInitialPos() {
	return initialPos;
}

Vec2 Player::GetPixelPos() {
	return pixelPos;
}

Vec2 Player::GetMapPos() {
	return cellPos;
}

int Player::GetScore() {
	return score;
}

int Player::GetLives() {
	return lives;
}

bool Player::IsEmpowered() {
	return isEmpowered;
}

void Player::SetInitialPos(Vec2 _initialPos) {
	initialPos = _initialPos;
	cellPos = initialPos;
	pixelPos = { cellPos.x*35, cellPos.y*35 };
}

void Player::SetScore(int _score) {
	score = _score;
}

void Player::SetLives(int _lives) {
	lives = _lives;
}

void Player::SetEmpowered(bool empowered) {
	isEmpowered = empowered;
}

void Player::Update(const Input &input, Map &map) {
	if (input.keyDown.at(Input::Key::W) || input.keyDown.at(Input::Key::UP))
		futureMovement = Movement::UP;
	else if (input.keyDown.at(Input::Key::A) || input.keyDown.at(Input::Key::LEFT))
		futureMovement = Movement::LEFT;
	else if (input.keyDown.at(Input::Key::S) || input.keyDown.at(Input::Key::DOWN))
		futureMovement = Movement::DOWN;
	else if (input.keyDown.at(Input::Key::D) || input.keyDown.at(Input::Key::RIGHT))
		futureMovement = Movement::RIGHT;

	switch (actualMovement) {
		case Movement::UP:
			switch (futureMovement) {
				case Movement::DOWN:
					actualMovement = Movement::DOWN;
					break;
				case Movement::LEFT:
					if (cellPos.y * 35 == pixelPos.y) {
						actualMovement = Movement::LEFT;
					}
					break;
				case Movement::RIGHT:
					if (cellPos.y * 35 == pixelPos.y) {
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
					if (cellPos.y * 35 == pixelPos.y) {
						actualMovement = Movement::LEFT;
					}
					break;
				case Movement::RIGHT:
					if (cellPos.y * 35 == pixelPos.y) {
						actualMovement = Movement::RIGHT;
					}
					break;
			}
			break;
		case Movement::LEFT:
			switch (futureMovement) {
				case Movement::UP:
					if (cellPos.x * 35 == pixelPos.x) {
						actualMovement = Movement::UP;
					}
					break;
				case Movement::DOWN:
					if (cellPos.x * 35 == pixelPos.x) {
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
					if (cellPos.x * 35 == pixelPos.x) {
						actualMovement = Movement::RIGHT;
					}
					break;
				case Movement::DOWN:
					if (cellPos.x * 35 == pixelPos.x) {
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
			if (map.GetCell({cellPos.x, cellPos.y - 1}) != Map::Cell::WALL)
				pixelPos.y -= 1;
			break;
		case Movement::DOWN:
			if (map.GetCell({ cellPos.x, cellPos.y + 1 }) != Map::Cell::WALL)
			pixelPos.y += 1;
			break;
		case Movement::LEFT:
			if (map.GetCell({ cellPos.x - 1, cellPos.y }) != Map::Cell::WALL)
			pixelPos.x -= 1;
			break;
		case Movement::RIGHT:
			if (map.GetCell({ cellPos.x + 1, cellPos.y }) != Map::Cell::WALL)
			pixelPos.x += 1;
			break;
		case Movement::STOP:
			break;
	}

	if (cellPos.x  != pixelPos.x/35 || cellPos.y != pixelPos.y/35) {
		cellPos.x = pixelPos.x / 35;
		cellPos.y = pixelPos.y / 35;
	}
}

void Player::Move(Map::Cell** map, Vec2) {

}

void Player::Draw() {
	renderer->PushSprite("spritesheet", { 640, 0, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
}

void Player::Dead() {

}
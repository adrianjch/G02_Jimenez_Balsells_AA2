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
					if (pixelPos.y % 35 == 0) {
						actualMovement = Movement::LEFT;
					}
					break;
				case Movement::RIGHT:
					if (pixelPos.y % 35 == 0) {
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
					if (pixelPos.y % 35 == 0) {
						actualMovement = Movement::LEFT;
					}
					break;
				case Movement::RIGHT:
					if (pixelPos.y % 35 == 0) {
						actualMovement = Movement::RIGHT;
					}
					break;
			}
			break;
		case Movement::LEFT:
			switch (futureMovement) {
				case Movement::UP:
					if (pixelPos.x % 35 == 0) {
						actualMovement = Movement::UP;
					}
					break;
				case Movement::DOWN:
					if (pixelPos.x % 35 == 0) {
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
					if (pixelPos.x % 35 == 0) {
						actualMovement = Movement::UP;
					}
					break;
				case Movement::DOWN:
					if (pixelPos.x % 35 == 0) {
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
			if (map.GetCell({pixelPos.x / 35, (pixelPos.y-1) / 35}) != Map::Cell::WALL)
				pixelPos.y -= 1;
			break;
		case Movement::DOWN:
			if (map.GetCell({pixelPos.x / 35, (pixelPos.y+35) / 35}) != Map::Cell::WALL)
				pixelPos.y += 1;
			break;
		case Movement::LEFT:
			if (map.GetCell({(pixelPos.x-1) / 35, pixelPos.y / 35}) != Map::Cell::WALL)
				pixelPos.x -= 1;
			break;
		case Movement::RIGHT:
			if (map.GetCell({(pixelPos.x+35) / 35, pixelPos.y / 35}) != Map::Cell::WALL)
				pixelPos.x += 1;
			break;
	}
		std::cout << cellPos.x << "," << cellPos.y << "  " << pixelPos.x << "," << pixelPos.y << (int)actualMovement << (int)futureMovement << std::endl;
}

void Player::Move(Map::Cell** map, Vec2) {

}

void Player::Draw() {
	renderer->PushSprite("spritesheet", { 640, 0, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
}

void Player::Dead() {

}
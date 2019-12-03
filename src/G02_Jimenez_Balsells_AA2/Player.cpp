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
			// codigo
			break;
	}
}

void Player::Move(Map::Cell** map, Vec2) {

}

void Player::Draw() {
	renderer->PushSprite("spritesheet", { 640, 0, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
}

void Player::Dead() {

}
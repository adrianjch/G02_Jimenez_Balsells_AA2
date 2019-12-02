#pragma once
#include "Player.h"

Player::Player() {

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

void Player::Update(const Input &input, Map::Cell** map) {

}

void Player::Move(Map::Cell** map, Vec2) {

}

void Player::Draw(std::string) {

}

void Player::Dead() {

}
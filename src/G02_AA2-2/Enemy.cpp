#pragma once
#include "Enemy.h"

Enemy::Enemy() {
	state = State::NORMAL;
}

Vec2 Enemy::GetInitialPos() const{
	return initialPos;
}

Vec2 Enemy::GetPixelPos() const{
	return pixelPos;
}

void Enemy::SetInitialPos(const Vec2 &_initialPos) {
	initialPos = { _initialPos.x*CELL_SIZE, _initialPos.y*CELL_SIZE };
	pixelPos = initialPos;
}
void Enemy::SetPixelPos(const Vec2 &pos) {
	pixelPos = pos;
}

Enemy::State Enemy::GetState() const {
	return state;
}

void Enemy::SetState(const State &_state) {
	state = _state;
	if (state == State::SCARED) {
		spriteNumber = 0;
	}
	else if (state == State::DEAD) {
		// contador a 0
		Reset();
	}
}

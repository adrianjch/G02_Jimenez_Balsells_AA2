#pragma once
#include "Enemy.h"

Enemy::Enemy() {

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

void Enemy::Dead() {

}
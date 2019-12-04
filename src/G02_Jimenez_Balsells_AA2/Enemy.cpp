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

Vec2 Enemy::GetMapPos() const{
	return cellPos;
}

void Enemy::SetInitialPos(const Vec2 &_initialPos) {
	initialPos = _initialPos;
	cellPos = initialPos;
	pixelPos = { cellPos.x*35, cellPos.y*35 };
}

void Enemy::Dead() {

}
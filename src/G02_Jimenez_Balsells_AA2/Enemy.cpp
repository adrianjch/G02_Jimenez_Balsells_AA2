#pragma once
#include "Enemy.h"

Enemy::Enemy() {
	renderer = renderer->Instance();
}

Vec2 Enemy::GetInitialPos() {
	return initialPos;
}

Vec2 Enemy::GetPixelPos() {
	return pixelPos;
}

Vec2 Enemy::GetMapPos() {
	return cellPos;
}

void Enemy::SetInitialPos(Vec2 _initialPos) {
	initialPos = _initialPos;
	cellPos = initialPos;
	pixelPos = { cellPos.x*35, cellPos.y*35 };
}

void Enemy::Dead() {

}
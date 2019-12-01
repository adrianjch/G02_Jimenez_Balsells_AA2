#pragma once
#include "Enemy.h"

Enemy::Enemy() {

}

Vec2 Enemy::GetPixelPos() {
	return pixelPos;
}

Vec2 Enemy::GetMapPos() {
	return cellPos;
}

void Enemy::SetInitialPos(Vec2 _initialPos) {
	initialPos = _initialPos;
}

void Enemy::Dead() {

}
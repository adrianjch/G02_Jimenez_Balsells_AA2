#pragma once
#include "Clyde.h"

Clyde::Clyde() {

}

void Clyde::Update(Map::Cell** map) {

}

void Clyde::Move(Map::Cell** map, Vec2) {

}

void Clyde::Draw() {
	renderer->PushSprite("spritesheet", { 0, 384, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
}
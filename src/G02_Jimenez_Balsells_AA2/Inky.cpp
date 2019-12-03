#pragma once
#include "Inky.h"

Inky::Inky() {

}

void Inky::Update(Map::Cell** map) {

}

void Inky::Move(Map::Cell** map, Vec2) {

}

void Inky::Draw() {
	renderer->PushSprite("spritesheet", { 0, 256, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
}
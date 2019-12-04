#pragma once
#include "Blinky.h"

Blinky::Blinky() {

}

void Blinky::Update(Map::Cell** map) {

}

void Blinky::Move(Map::Cell** map, Vec2) {

}

void Blinky::Draw() const{
	Renderer::Instance()->PushSprite("spritesheet", { 0, 128, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
}
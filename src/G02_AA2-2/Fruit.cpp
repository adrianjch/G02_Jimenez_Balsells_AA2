#pragma once
#include "Fruit.h"

Fruit::Fruit( const Vec2 &_initialPos) {
	initialPos = _initialPos;
	type = static_cast<FruitType>(rand() % static_cast<int>(FruitType::COUNT));
	active = false;
}

Vec2 Fruit::GetInitialPos() const{
	return initialPos;
}

Fruit::FruitType Fruit::GetType() const{
	return type;
}

void Fruit::SetInitialPos(const Vec2 &_initialPos) {
	initialPos = _initialPos;
}

void Fruit::Update() {
	timeCounter += 1000 / MAX_FRAMERATE;

	if (timeCounter >= 10000.0f) {
		timeCounter = 0.0f;
		active = true;
	}
}

void Fruit::Draw() const{
	if (active) {
		switch (type) {
		case FruitType::CHERRY:
			Renderer::Instance()->PushSprite("spritesheet", { 0, 768, 128, 128 }, { initialPos.x, initialPos.y, 35, 35 });
			break;
		case FruitType::ORANGE:
			Renderer::Instance()->PushSprite("spritesheet", { 256, 768, 128, 128 }, { initialPos.x, initialPos.y, 35, 35 });
			break;
		case FruitType::SRTRAWBERRY:
			Renderer::Instance()->PushSprite("spritesheet", { 128, 768, 128, 128 }, { initialPos.x, initialPos.y, 35, 35 });
			break;
		}
	}

}
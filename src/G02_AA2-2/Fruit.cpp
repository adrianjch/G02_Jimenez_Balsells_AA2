#pragma once
#include "Fruit.h"

Fruit::Fruit() {
	type = static_cast<FruitType>(rand() % static_cast<int>(FruitType::COUNT));
	active = false;
	timeToSpawn = 10.0f;
	timeCounter = 0.0f;
}

Vec2 Fruit::GetInitialPos() const{
	return initialPos;
}

Fruit::FruitType Fruit::GetType() const{
	return type;
}

bool Fruit::IsActive() const {
	return active;
}

void Fruit::SetInitialPos(const Vec2 &_initialPos) {
	initialPos = _initialPos;
}

void Fruit::Update(const Vec2 &playerPos) {
	if (!active) {
		timeCounter += static_cast<float>(1.0f / MAX_FRAMERATE);
		if (timeCounter >= timeToSpawn) {
			if ((sqrt((pow(playerPos.x - initialPos.x, 2) + pow(playerPos.y - initialPos.y, 2))) < 25))
				timeCounter = timeToSpawn - 2.0f;
			else 
				active = true;

		}
	}
}

void Fruit::Destroy() {
	active = false;
	timeToSpawn = 15.0f;
	timeCounter = 0.0f;
	type = static_cast<FruitType>(rand() % static_cast<int>(FruitType::COUNT));
}

void Fruit::Draw() const{
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
#pragma once
#include "Fruit.h"

Fruit::Fruit( const Vec2 &_initialPos) {
	initialPos = _initialPos;
	type = static_cast<FruitType>(rand() % static_cast<int>(FruitType::COUNT));

	switch (type) {
	case FruitType::CHERRY:
		score = 10;
		break;
	case FruitType::ORANGE:
		score = 20;
		break;
	case FruitType::SRTRAWBERRY:
		score = 15;
		break;
	}
}

Vec2 Fruit::GetInitialPos() const{
	return initialPos;
}

Fruit::FruitType Fruit::GetType() const{
	return type;
}

int Fruit::GetScore() const{
	return score;
}

void Fruit::SetInitialPos(const Vec2 &_initialPos) {
	initialPos = _initialPos;
}

void Fruit::Update() {

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
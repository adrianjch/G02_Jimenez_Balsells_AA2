#pragma once
#include "Fruit.h"

Fruit::Fruit() {

}

Vec2 Fruit::GetInitialPos() {
	return initialPos;
}

Fruit::FruitType Fruit::GetType() {
	return type;
}

void Fruit::SetInitialPos(Vec2 _initialPos) {
	initialPos = _initialPos;
}

void Fruit::Update() {

}

void Fruit::Draw(std::string) {


}
#pragma once
#include "Fruit.h"

Fruit::Fruit() {

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

}

void Fruit::Draw() const{


}
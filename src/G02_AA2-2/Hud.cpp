#pragma once
#include "Hud.h"

Hud::Hud() {

}

void Hud::Draw(const Player &p) const{
	Renderer::Instance()->PushSprite("spritesheet", { 996, 768, 128, 128 }, { 700, 0, 200, 700 });

	// Render score
	std::string scoreStr;
	int tmp = p.GetScore();
	int counter = 0;
	do {
		scoreStr = std::to_string(tmp % 10);
		Renderer::Instance()->PushImage(scoreStr, { 840 - (counter*42), 40, Renderer::Instance()->GetTextureSize(scoreStr).x, Renderer::Instance()->GetTextureSize(scoreStr).y });
		tmp /= 10;
		counter++;

	} while ( counter < 4);

	counter = 0;
	tmp = p.GetLives();
	
	// Render lives
	for (int i = 0; i < tmp; i++) {
		Renderer::Instance()->PushSprite("spritesheet", { 896, 0, 128, 128 }, { 705 + (i*60), 630, 70, 70 });
	}

	// Render fruits
	for (int i = 0; i < 3; i++) {
		Renderer::Instance()->PushSprite("spritesheet", { i * 128,768, 128,128 }, { 710, 200 + 70 * i, 70, 70 });
		Renderer::Instance()->PushImage("X", { 775, 210 + 70 * i, 50, 55});
		switch (i) {
			case 0:
				scoreStr = std::to_string(p.GetFruitScore(Fruit::FruitType::CHERRY));
				Renderer::Instance()->PushImage(scoreStr, { 830, 205 + 70* i, Renderer::Instance()->GetTextureSize(scoreStr).x, Renderer::Instance()->GetTextureSize(scoreStr).y });
				break;
			case 1:
				scoreStr = std::to_string(p.GetFruitScore(Fruit::FruitType::SRTRAWBERRY));
				Renderer::Instance()->PushImage(scoreStr, { 830, 205 + 70 * i, Renderer::Instance()->GetTextureSize(scoreStr).x, Renderer::Instance()->GetTextureSize(scoreStr).y });
				break;
			case 2:
				scoreStr = std::to_string(p.GetFruitScore(Fruit::FruitType::ORANGE));
				Renderer::Instance()->PushImage(scoreStr, { 830, 205 + 70 * i, Renderer::Instance()->GetTextureSize(scoreStr).x, Renderer::Instance()->GetTextureSize(scoreStr).y });
				break;

		}
		
	}
}
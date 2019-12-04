#pragma once
#include "Hud.h"

Hud::Hud() {

}

void Hud::Draw(const Player &p) const{
	Renderer::Instance()->PushSprite("spritesheet", { 996, 768, 128, 128 }, { 700, 0, 200, 700 });

	std::string scoreStr;

	int tmp = p.GetScore();
	int counter = 0;
	do {
		scoreStr = std::to_string(tmp % 10);
		Renderer::Instance()->PushImage(scoreStr, { 830-(counter*30), 100, Renderer::Instance()->GetTextureSize(scoreStr).x, Renderer::Instance()->GetTextureSize(scoreStr).y });
		tmp /= 10;
		counter++;

	} while ( counter < 4);

	counter = 0;
	tmp = p.GetLives();
	
	for (int i = 0; i < tmp; i++) {
		Renderer::Instance()->PushSprite("spritesheet", { 896, 0, 128, 128 }, { 705 + (i*60), 630, 70, 70 });
	}
}
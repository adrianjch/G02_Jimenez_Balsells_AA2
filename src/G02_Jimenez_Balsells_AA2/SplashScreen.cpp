#include "SplashScreen.h"
#include <iostream>

SplashScreen::SplashScreen() {
	state = SceneState::RUNNING;
	timer = clock();
}

void SplashScreen::Update(const Input &input) {
	duration = (clock() - timer) / static_cast<float>(CLOCKS_PER_SEC);
	if (duration >= 3.f)
		state = SceneState::MENU_STATE;
}

void SplashScreen::Draw() const{
	Renderer::Instance()->Clear();

	Vec2 size = Renderer::Instance()->GetTextureSize("title");

	Renderer::Instance()->PushImage("title", { SCREEN_WIDTH/2 - size.x/2, 150, size.x, size.y });

	// Animation
	if (duration < 1.1f)
		Renderer::Instance()->PushSprite("spritesheet", { 768, 768, 128, 128 }, { 300, 425, 50, 50 });
	if (duration < 1.7f)
		Renderer::Instance()->PushSprite("spritesheet", { 768, 768, 128, 128 }, { 400, 425, 50, 50 });
	if (duration < 2.4f)
		Renderer::Instance()->PushSprite("spritesheet", { 768, 768, 128, 128 }, { 500, 425, 50, 50 });
	Renderer::Instance()->PushSprite("spritesheet", { 768, 768, 128, 128 }, { 600, 425, 50, 50 });
	Renderer::Instance()->PushSprite("spritesheet", { 512, 0, 128, 128 }, { static_cast<int>(duration*160) + 110, 400, 100, 100 });

	Renderer::Instance()->Render();
}
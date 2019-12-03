#include "SplashScreen.h"
#include <iostream>

SplashScreen::SplashScreen() {
	state = SceneState::RUNNING;
	timer = clock();
	renderer = Renderer::Instance();
}

void SplashScreen::Update(const Input &input) {
	if ((clock() - timer) / static_cast<float>(CLOCKS_PER_SEC) >= 3.f)
		state = SceneState::MENU_STATE;
}

void SplashScreen::Draw() {
	Vec2 size = renderer->GetTextureSize("title");

	renderer->Clear();
	renderer->PushImage("title", { SCREEN_WIDTH/2 - size.x/2, SCREEN_HEIGHT/2 - size.y/2, size.x, size.y });
	renderer->Render();
}
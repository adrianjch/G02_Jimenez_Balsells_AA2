#include "SplashScreen.h"
#include <iostream>

SplashScreen::SplashScreen() {
	state = SceneState::RUNNING;
	timer = clock();
}

void SplashScreen::Update(const Input &input) {
	if ((clock() - timer) / static_cast<float>(CLOCKS_PER_SEC) >= 3.f)
		state = SceneState::MENU_STATE;
}

void SplashScreen::Draw() const{
	Renderer::Instance()->Clear();

	Vec2 size = Renderer::Instance()->GetTextureSize("title");

	Renderer::Instance()->PushImage("title", { SCREEN_WIDTH/2 - size.x/2, SCREEN_HEIGHT/2 - size.y/2, size.x, size.y });
	Renderer::Instance()->Render();
}
#include "SplashScreen.h"

SplashScreen::SplashScreen() {
	state = SceneState::RUNNING;
	timer = clock();
}

void SplashScreen::Update() {
	if ((clock() - timer) / static_cast<float>(CLOCKS_PER_SEC) >= 3.f)
		state = SceneState::MENU_STATE;
}

void SplashScreen::Draw() {

}
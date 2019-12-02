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

void SplashScreen::Draw() {
	std::cout << "\n\n";
	std::cout << " лллллллл     лллллл     лллллллл лл      лл   лллллл   ллл     лл\n";
	std::cout << " лл      лл лл      лл лл         лллл  лллл лл      лл лллл    лл\n";
	std::cout << " лл      лл лл      лл лл         лл  лл  лл лл      лл лл лл   лл\n";
	std::cout << " лллллллл   лллллллллл лл         лл      лл лллллллллл лл  лл  лл\n";
	std::cout << " лл         лл      лл лл         лл      лл лл      лл лл   лл лл\n";
	std::cout << " лл         лл      лл лл         лл      лл лл      лл лл    лллл\n";
	std::cout << " лл         лл      лл   лллллллл лл      лл лл      лл лл     ллл\n";
	std::cout << "\n\n";
}
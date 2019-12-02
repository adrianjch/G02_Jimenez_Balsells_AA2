#include "Menu.h"

Menu::Menu() {
	state = SceneState::RUNNING;
	renderer = Renderer::Instance();
}

void Menu::Update(const Input &input) {
	std::cout << "menu";
	play.Update(input);
	ranking.Update(input);
	sound.Update(input);
	exit.Update(input);
}

void Menu::Draw() {
	renderer->Clear();
	play.Draw();
	ranking.Draw();
	sound.Draw();
	exit.Draw();
	renderer->Render();
}
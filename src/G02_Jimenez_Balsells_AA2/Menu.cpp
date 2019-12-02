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
	if (play.IsClicked)
		state = SceneState::PLAY_STATE;
	else if (ranking.IsClicked)
		state = SceneState::RANKING_STATE;
	/*else if (sound.IsClicked) {
		if (Mix_PausedMusic())
			Mix_ResumeMusic();
		else
			Mix_PauseMusic();
	}*/
	else if (exit.IsClicked)
		state = SceneState::EXIT_STATE;
}

void Menu::Draw() {
	renderer->Clear();
	play.Draw();
	ranking.Draw();
	sound.Draw();
	exit.Draw();
	renderer->Render();
}
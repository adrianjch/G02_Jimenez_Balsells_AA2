#include "Menu.h"

Menu::Menu() {
	state = SceneState::RUNNING;
}

void Menu::Update(const Input &input) {
	play.Update(input);
	ranking.Update(input);
	sound.Update(input);
	exit.Update(input);

	if (play.IsClicked())
		state = SceneState::PLAY_STATE;
	else if (ranking.IsClicked())
		state = SceneState::RANKING_STATE;
	/*else if (sound.IsClicked()) {
		if (Mix_PausedMusic())
			Mix_ResumeMusic();
		else
			Mix_PauseMusic();
	}*/
	else if (exit.IsClicked())
		state = SceneState::EXIT_STATE;
}

void Menu::Draw() const{
	Renderer::Instance()->Clear();
	play.Draw();
	ranking.Draw();
	sound.Draw();
	exit.Draw();
	Renderer::Instance()->Render();
}
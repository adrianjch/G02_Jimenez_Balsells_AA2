#include "Game.h"

Game::Game() {
	state = SceneState::START_GAME;
	renderer = renderer->Instance();
}

void Game::Update(const Input &input) {
	switch (Scene::GetState()) {
	case SceneState::START_GAME:
		if (input.key.at(Input::Key::SPACE)) {
			state = SceneState::RUNNING;
		}
		else if (input.key.at(Input::Key::ESCAPE)) {
			state = SceneState::MENU_STATE;
		}
		break;
	case SceneState::RUNNING:
		if (input.key.at(Input::Key::P)) {
			state = SceneState::PAUSE;
		}
		break;
	case SceneState::GAME_OVER:
		state = SceneState::RANKING_STATE;
		break;
	case SceneState::PAUSE:
		if(input.key.at(Input::Key::ESCAPE)) {
			state = SceneState::MENU_STATE;
		}
		else if (input.key.at(Input::Key::SPACE)) {
			state = SceneState::RUNNING;
		}
	}
}

void Game::Draw() {
	renderer->Clear();
	switch (Scene::GetState()) {
		case SceneState::START_GAME:
			renderer->PushImage("press to play", { SCREEN_WIDTH/2 - 200, SCREEN_HEIGHT/2, renderer->GetTextureSize("press to play").x, renderer->GetTextureSize("press to play").y });
			break;
		case SceneState::RUNNING:

			break;

		case SceneState::GAME_OVER:

			break;
		case SceneState::PAUSE:
			sound.Draw();
			break;
	}
	renderer->Render();
}
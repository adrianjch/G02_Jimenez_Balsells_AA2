#include "Game.h"

Game::Game() {
	state = SceneState::START_GAME;
	renderer = renderer->Instance();
}

void Game::Update(const Input &input) {
	//if(input.key.at[])
	//	state = SceneState::RUNNING;
}

void Game::Draw() {
	renderer->Clear();

	renderer->Render();
}
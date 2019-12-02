#include "GameController.h"
#include "SplashScreen.h"
#include "Menu.h"
#include "Ranking.h"
#include "Game.h"
#include <Windows.h>

GameController::GameController() {
	scene = new SplashScreen();
	gameState = GameState::SPLASH_SCREEN;
	renderer = Renderer::Instance();
	renderer->LoadFont({"buttons", "../../res/ttf/PAC-FONT.TTF", 72});
	renderer->LoadTextureText("buttons", { "play normal", "PLAY", {255,0,0,255}, 500, 200 });
}

void GameController::Play() {
	bool finish = false;
	while (!finish) {
		// INPUT
		inputManager.ReadInput();

		// UPDATE AND DRAW
		switch (gameState) {
			case GameController::GameState::SPLASH_SCREEN:
				if (scene->GetState() == Scene::SceneState::RUNNING) {
					scene->Update(inputManager.GetInput());
					scene->Draw();
				}
				else if (scene->GetState() == Scene::SceneState::MENU_STATE) {
					delete scene;
					scene = new Menu();
					gameState = GameState::MENU;
				}
				break;
			case GameController::GameState::MENU:
				if (scene->GetState() == Scene::SceneState::RUNNING) {
					scene->Update(inputManager.GetInput());
					scene->Draw();
				}
				else if (scene->GetState() == Scene::SceneState::PLAY_STATE) {
					delete scene;
					scene = new Game();
					gameState = GameState::GAME;
				}
				else if (scene->GetState() == Scene::SceneState::RANKING_STATE) {
					delete scene;
					scene = new Ranking();
					gameState = GameState::RANKING;
				}
				else if (scene->GetState() == Scene::SceneState::EXIT_STATE) {
					delete scene;
					finish = true;
				}
				break;
			case GameController::GameState::GAME:
				break;
			case GameController::GameState::RANKING:
				if (scene->GetState() == Scene::SceneState::RUNNING) {
					scene->Update(inputManager.GetInput());
					scene->Draw();
				}
				else if (scene->GetState() == Scene::SceneState::MENU_STATE) {
					delete scene;
					scene = new Menu();
					gameState = GameState::MENU;
				}
				break;
		}
		//FRAME CONTROLLER
		Sleep(1000);
	}
}
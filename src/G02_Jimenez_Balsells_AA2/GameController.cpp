#include "GameController.h"
#include "SplashScreen.h"
#include "Menu.h"
#include "Ranking.h"
#include "Game.h"

GameController::GameController() {
	scene = new SplashScreen();
	gameState = GameState::SPLASH_SCREEN;
}

void GameController::Play() {
	bool finish = false;
	while (!finish) {
		switch (gameState) {
			case GameController::GameState::SPLASH_SCREEN:
				if (scene->GetState() == Scene::SceneState::RUNNING) {
					scene->Update();
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
					scene->Update();
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
					scene->Update();
					scene->Draw();
				}
				else if (scene->GetState() == Scene::SceneState::MENU_STATE) {
					delete scene;
					scene = new Menu();
					gameState = GameState::MENU;
				}
				break;
		}
		//frame controller
	}
}
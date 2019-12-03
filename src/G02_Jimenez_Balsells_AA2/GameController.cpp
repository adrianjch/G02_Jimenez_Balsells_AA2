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
	renderer->LoadFont({"buttons", "../../res/ttf/PAC-FONT.TTF", 60});
	renderer->LoadFont({ "splashScreenText", "../../res/ttf/PAC-FONT.TTF", 100 });

	renderer->LoadTextureText("splashScreenText", { "title", "pacman", {255,255,0,255}, 200, 600 });

	renderer->LoadTextureText("buttons", { "play normal", "PLAY", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "play hover", "play", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "ranking normal", "RANKING", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "ranking hover", "ranking", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "sound normal", "SOUND", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "sound hover", "sound", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "exit normal", "EXIT", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "exit hover", "exit", {255,0,0,255}, 200, 600 });

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
				if (scene->GetState() == Scene::SceneState::START_GAME) {
					scene->Update(inputManager.GetInput());
					scene->Draw();
				}
				else if (scene->GetState() == Scene::SceneState::RUNNING) {
					scene->Update(inputManager.GetInput());
					scene->Draw();
				}
				else if (scene->GetState() == Scene::SceneState::GAME_OVER) {

				}
				else if (scene->GetState() == Scene::SceneState::RANKING_STATE) {

				}
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
		// Sleep(1000);
	}
}
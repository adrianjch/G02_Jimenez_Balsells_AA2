#include "GameController.h"
#include "SplashScreen.h"
#include "Menu.h"
#include "Ranking.h"
#include "Game.h"
#include "Music.h"
#include "SDL_Utils.h"
#include <Windows.h>


GameController::GameController() {
	scene = new SplashScreen();
	gameState = GameState::SPLASH_SCREEN;
}

void GameController::Run() {
	unsigned int startFrame, endFrame;
	bool finish = false;
	while (!finish) {
		startFrame = GetTicks();
		// INPUT
		inputManager.ReadInput();

		// UPDATE AND DRAW
		switch (gameState) {
			case GameController::GameState::SPLASH_SCREEN:
				switch (scene->GetState()) {
					case Scene::SceneState::RUNNING:
						scene->Update(inputManager.GetInput());
						scene->Draw();
						break;
					case Scene::SceneState::MENU_STATE:
						delete scene;
						scene = new Menu();
						gameState = GameState::MENU;
						break;
				}
				break;
			case GameController::GameState::MENU:
				switch (scene->GetState()) {
					case Scene::SceneState::RUNNING: 
						scene->Update(inputManager.GetInput());
						scene->Draw();
						break;
					case Scene::SceneState::PLAY_STATE:
						delete scene;
						scene = new Game();
						gameState = GameState::GAME;
						break;
					case Scene::SceneState::RANKING_STATE:
						delete scene;
						scene = new Ranking();
						gameState = GameState::RANKING;
						break;
					case Scene::SceneState::EXIT_STATE:
						delete scene;
						finish = true;
						break;
				}
				break;
			case GameController::GameState::GAME:
				switch(scene->GetState()) {
					case Scene::SceneState::RANKING_STATE:
						delete scene;
						scene = new Ranking();
						gameState = GameState::RANKING;
						break;
					case Scene::SceneState::MENU_STATE:
						delete scene;
						scene = new Menu();
						gameState = GameState::MENU;
						break;
					default:
						scene->Update(inputManager.GetInput());
						scene->Draw();
						break;
				}
				break;
			case GameController::GameState::RANKING:
				switch (scene->GetState()) {
					case Scene::SceneState::RUNNING:
						scene->Update(inputManager.GetInput());
						scene->Draw();
						break;
					case Scene::SceneState::MENU_STATE:
						delete scene;
						scene = new Menu();
						gameState = GameState::MENU;						
						break;				
				}
				break;
		}
		//FRAME CONTROLLER
		endFrame = GetTicks();
		if (endFrame - startFrame < 1000 / MAX_FRAMERATE)
			Delay((1000 / MAX_FRAMERATE) - (endFrame - startFrame));
	}
}
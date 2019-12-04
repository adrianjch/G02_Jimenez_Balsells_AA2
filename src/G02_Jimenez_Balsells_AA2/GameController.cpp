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
	renderer->LoadFont({ "hud", "../../res/ttf/Gameplay.ttf", 40 });

	// Loading splashScreen text
	renderer->LoadTextureText("splashScreenText", { "title", "pacman", {255,255,0,255}, 200, 600 });

	// Loading menu buttons text
	renderer->LoadTextureText("buttons", { "play normal", "PLAY", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "play hover", "play", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "ranking normal", "RANKING", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "ranking hover", "ranking", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "sound normal", "SOUND", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "sound hover", "sound", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "exit normal", "EXIT", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "exit hover", "exit", {255,0,0,255}, 200, 600 });

	// Loading Ranking buttons text
	renderer->LoadTextureText("buttons", { "menu normal", "MENU", {255,0,0,255}, 200, 600 });
	renderer->LoadTextureText("buttons", { "menu hover", "menu", {255,0,0,255}, 200, 600 });

	// Loading Game Text
	renderer->LoadTextureText("buttons", { "press to play", "PrEsS sPaCe To StArT", {255,0 ,0 ,255}, 200, 600 });
	renderer->LoadTextureText("hud", { "0", "0", {0,0 ,0 ,255}, 200, 600 });
	renderer->LoadTextureText("hud", { "1", "1", {0,0 ,0 ,255}, 200, 600 });
	renderer->LoadTextureText("hud", { "2", "2", {0,0 ,0 ,255}, 200, 600 });
	renderer->LoadTextureText("hud", { "3", "3", {0,0 ,0 ,255}, 200, 600 });
	renderer->LoadTextureText("hud", { "4", "4", {0,0 ,0 ,255}, 200, 600 });
	renderer->LoadTextureText("hud", { "5", "5", {0,0 ,0 ,255}, 200, 600 });
	renderer->LoadTextureText("hud", { "6", "6", {0,0 ,0 ,255}, 200, 600 });
	renderer->LoadTextureText("hud", { "7", "7", {0,0 ,0 ,255}, 200, 600 });
	renderer->LoadTextureText("hud", { "8", "8", {0,0 ,0 ,255}, 200, 600 });
	renderer->LoadTextureText("hud", { "9", "9", {0,0 ,0 ,255}, 200, 600 });


	// Loading Spritesheet
	renderer->LoadTexture("spritesheet", "../../res/img/PacManSpritesheet.png");
}

void GameController::Play() {
	bool finish = false;
	while (!finish) {
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
		Sleep(17);
	}
}
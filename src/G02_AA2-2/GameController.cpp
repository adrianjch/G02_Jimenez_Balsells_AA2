#include "GameController.h"
#include "SplashScreen.h"
#include "Menu.h"
#include "Ranking.h"
#include "Game.h"
#include "Music.h"
#include <Windows.h>


GameController::GameController() {
	scene = new SplashScreen();
	gameState = GameState::SPLASH_SCREEN;
	Renderer::Instance()->LoadFont({"buttons", "../../res/ttf/PAC-FONT.TTF", 60});
	Renderer::Instance()->LoadFont({ "title", "../../res/ttf/PAC-FONT.TTF", 100 });
	Renderer::Instance()->LoadFont({ "hud", "../../res/ttf/Gameplay.ttf", 55 });
	Renderer::Instance()->LoadFont({ "pac40", "../../res/ttf/PAC-FONT.TTF", 40 });

	// Loading splashScreen text
	Renderer::Instance()->LoadTextureText("title", { "title", "pacman", {255,255,0,255}, 200, 600 });

	// Loading menu buttons text
	Renderer::Instance()->LoadTextureText("buttons", { "play normal", "PLAY", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "play hover", "play", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "ranking normal", "RANKING", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "ranking hover", "ranking", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "sound normal", "SOUND", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "sound hover", "sound", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "exit normal", "EXIT", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "exit hover", "exit", {255,0,0,255}, 200, 600 });

	// Loading Ranking buttons text
	Renderer::Instance()->LoadTextureText("title", { "ranking", "ranking", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "menu normal", "MENU", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "menu hover", "menu", {255,0,0,255}, 200, 600 });

	// Loading Game Text
	Renderer::Instance()->LoadTextureText("pac40", { "press to play", "PrEsS sPaCe To StArT", {255,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("pac40", { "press to continue", "PrEsS sPaCe To CoNtInUe", {255,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("title", { "stop", "StOp", {255,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("pac40", { "sound: normal", "SOUND:", {255,255,255,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("pac40", { "sound: hover", "sound:", {255,255,255,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "on", "on", {0,255,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "off", "off", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "0", "0", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "1", "1", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "2", "2", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "3", "3", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "4", "4", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "5", "5", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "6", "6", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "7", "7", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "8", "8", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "9", "9", {0,0 ,0 ,255}, 200, 600 });

	// Loading Spritesheet
	Renderer::Instance()->LoadTexture("spritesheet", "../../res/img/PacManSpritesheet.png");

	// Loading Music
	Music::Instance()->LoadMusic("waka waka", "../../res/au/pacman_waka_waka.mp3");
	Music::Instance()->LoadMusic("begin", "../../res/au/pacman_beginning.mp3");
	Music::Instance()->LoadMusic("death", "../../res/au/pacman_death.mp3");
}

void GameController::Run() {
	unsigned int startFrame, endFrame;
	bool finish = false;
	while (!finish) {
		startFrame = SDL_GetTicks();
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
		endFrame = SDL_GetTicks();
		if (endFrame - startFrame < 1000 / MAX_FRAMERATE)
			SDL_Delay((1000 / MAX_FRAMERATE) - (endFrame - startFrame));
	}
}
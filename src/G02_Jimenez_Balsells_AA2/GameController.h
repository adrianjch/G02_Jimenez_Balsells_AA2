#pragma once
#include "Scene.h"
#include "InputManager.h"
#include "Renderer.h"

class GameController {
private:
	enum class GameState{ SPLASH_SCREEN, MENU, GAME, RANKING };
	GameState gameState;
	Scene* scene;
	InputManager inputManager;
	Renderer* renderer;
public:
	GameController();
	void Play();
};
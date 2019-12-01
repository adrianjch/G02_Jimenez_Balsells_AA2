#pragma once
#include "Scene.h"

class GameController {
private:
	enum class GameState{ SPLASH_SCREEN, MENU, GAME, RANKING };
	GameState gameState;
	Scene* scene;
public:
	GameController();
	void Play();
};
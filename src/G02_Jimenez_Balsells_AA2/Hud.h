#pragma once
#include "Renderer.h"
#include "Player.h"

class Hud {
private:
	int windowHeight;
	int windowWidth;
	Renderer* renderer;
public:
	Hud();
	void Draw(Player);
};

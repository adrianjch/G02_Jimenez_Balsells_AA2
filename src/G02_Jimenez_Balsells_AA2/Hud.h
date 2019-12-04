#pragma once
#include "Renderer.h"
#include "Player.h"

class Hud {
private:
	int windowHeight;
	int windowWidth;
public:
	Hud();
	void Draw(const Player &) const;
};

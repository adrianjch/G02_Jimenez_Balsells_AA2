#pragma once
#include "Scene.h"
#include "Button.h"
#include "Renderer.h"

class Ranking : public Scene {
private:
	Button menu{ "menu normal", "menu hover", {SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 } };
	Renderer *renderer;
public:
	Ranking();
	void Update(const Input &);
	void Draw();
};
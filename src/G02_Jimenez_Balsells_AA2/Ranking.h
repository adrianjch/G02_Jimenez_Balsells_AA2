#pragma once
#include "Scene.h"
#include "Button.h"
#include "Renderer.h"

class Ranking : public Scene {
private:
	Button menu{ "menu normal", "menu hover", { 130, SCREEN_HEIGHT - 50 } };
public:
	Ranking();
	void Update(const Input &);
	void Draw() const;
};
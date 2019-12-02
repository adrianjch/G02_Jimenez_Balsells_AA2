#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Button.h"

class Menu : public Scene {
private:
	Button play{ "play normal", "play hover", {100,500} };
	Button ranking{ "ranking normal", "ranking hover", {100,500} };
	Button sound{ "sound normal", "sound hover", {100,500} };
	Button exit{ "exit normal", "exit hover", {100,500} };
	Renderer* renderer;
public:
	Menu();
	void Update(const Input &);
	void Draw();
};
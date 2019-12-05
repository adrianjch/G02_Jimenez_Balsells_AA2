#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Button.h"
#include "Constants.h"

class Menu : public Scene {
private:
	Button play{ "play normal", "play hover", {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4 - 100 } };
	Button ranking{ "ranking normal", "ranking hover", {SCREEN_WIDTH / 2, 2 * SCREEN_HEIGHT / 4 - 100 } };
	Button sound{ "sound normal", "sound hover", {SCREEN_WIDTH / 2, 3 * SCREEN_HEIGHT / 4 - 100} };
	Button exit{ "exit normal", "exit hover", {SCREEN_WIDTH / 2, 4 * SCREEN_HEIGHT / 4 - 100} };
public:
	Menu();
	void Update(const Input &);
	void Draw() const;
};
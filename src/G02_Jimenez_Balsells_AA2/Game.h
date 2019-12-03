#pragma once
#include "Scene.h"
#include "Player.h"
#include <string>
#include "Renderer.h"
#include "Button.h"
#include "Constants.h"


class Game : public Scene {
private:
	std::string imageID;
	std::string imagePath;
	Player player;
	Renderer *renderer;
	Text StartPlaying{};
	Button sound{ "sound normal", "sound hover", {SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2} };
public:
	Game();
	void Update(const Input &);
	void Draw();
};
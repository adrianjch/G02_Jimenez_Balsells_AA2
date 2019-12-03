#pragma once
#include "Scene.h"
#include "Player.h"
#include <string>
#include "Renderer.h"

class Game : public Scene {
private:
	std::string imageID;
	std::string imagePath;
	Player player;
	Renderer *renderer;
public:
	Game();
	void Update(const Input &);
	void Draw();
};
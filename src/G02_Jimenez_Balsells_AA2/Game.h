#pragma once
#include "Scene.h"
#include "Player.h"
#include <string>

class Game : public Scene {
private:
	std::string imageID;
	std::string imagePath;
	Player player;
public:
	Game();
	void Update(const Input &);
	void Draw();
};
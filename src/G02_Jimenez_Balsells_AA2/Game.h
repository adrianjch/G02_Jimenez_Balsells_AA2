#pragma once
#include "Scene.h"
#include <string>

class Game : public Scene {
private:
	std::string imageID;
	std::string imagePath;
public:
	Game();
	void Update();
	void Draw();
};
#pragma once
#include "Scene.h"

class Menu : public Scene {
private:
	Button play;
	Button ranking;
	Button sound;
	Button exit;
public:
	Menu();
	void Update();
	void Draw();
};
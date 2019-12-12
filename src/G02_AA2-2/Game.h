#pragma once
#include "Scene.h"
#include "Player.h"
#include "Renderer.h"
#include "Button.h"
#include "Constants.h"
#include "Blinky.h"
#include "Inky.h"
#include "Clyde.h"
#include "Fruit.h"
#include "Hud.h"
#include "Music.h"
#include <string>
#include <ctime>


class Game : public Scene {
private:
	Map map;
	Player player;
	Blinky blinky;
	Inky inky;
	Clyde clyde;
	Fruit* fruit;
	Hud hud;
	Button sound;
public:
	Game();
	void Update(const Input &);
	void Draw() const;
};
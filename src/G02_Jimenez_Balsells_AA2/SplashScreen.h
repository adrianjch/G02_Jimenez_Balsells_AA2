#pragma once
#include "Scene.h"
#include <ctime>
#include "Renderer.h"
#include "Constants.h"

class SplashScreen : public Scene {
private:
	clock_t timer;
	Renderer *renderer;
public:
	SplashScreen();
	void Update(const Input &);
	void Draw();
};
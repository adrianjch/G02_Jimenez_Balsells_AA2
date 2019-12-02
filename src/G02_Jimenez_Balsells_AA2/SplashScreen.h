#pragma once
#include "Scene.h"
#include <ctime>

class SplashScreen : public Scene {
private:
	clock_t timer;
public:
	SplashScreen();
	void Update(const Input &);
	void Draw();
};
#pragma once
#include "Scene.h"
#include "Button.h"
#include "Renderer.h"

class Ranking : public Scene {
private:
	Button menu;
public:
	Ranking();
	void Update(const Input &);
	void Draw() const;
};
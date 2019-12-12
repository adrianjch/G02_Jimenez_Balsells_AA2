#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Button.h"
#include "Constants.h"

class Menu : public Scene {
private:
	Button play;
	Button ranking;
	Button sound;
	Button exit;
public:
	Menu();
	void Update(const Input &);
	void Draw() const;
};
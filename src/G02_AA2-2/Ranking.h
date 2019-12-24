#pragma once
#include "Scene.h"
#include "Button.h"
#include "Renderer.h"

class Ranking : public Scene {
private:
	Button menu;
	std::vector<std::pair<std::string, int>> ranking;
public:
	Ranking();
	void ReadRanking();
	void Update(const Input &);
	void Draw() const;
};
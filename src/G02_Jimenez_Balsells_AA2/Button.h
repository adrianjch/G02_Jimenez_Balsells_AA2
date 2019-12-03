#pragma once
#include "Types.h"
#include "Renderer.h"

class Button {
private:
	bool clicked;
	bool hover;
	Vec2 pos;
	Vec2 size;
	std::string normalID, hoverID;
	Renderer* renderer;
public:
	Button(std::string, std::string, Vec2);
	bool CheckIfHover(Vec2);
	bool IsClicked();
	void Update(const Input &);
	void Draw();
};
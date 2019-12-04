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
public:
	Button(std::string, std::string, Vec2);
	bool CheckIfHover(const Vec2 &) const;
	bool IsClicked() const;
	void Update(const Input &);
	void Draw() const;
};
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
	Button();
	bool CheckIfHover(const Vec2 &) const;
	bool IsClicked() const;
	void SetTextures(const std::string &, const std::string &);
	void SetPos(const Vec2 &);
	void Update(const Input &);
	void Draw() const;
};
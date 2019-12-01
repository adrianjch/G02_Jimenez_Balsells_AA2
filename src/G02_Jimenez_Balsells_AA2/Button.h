#pragma once

class Button {
private:
	bool clicked;
	Text text;
	Font font;

public:
	Button();
	bool CheckIfHover(Vec2);
	void Update();
	void Draw();
};
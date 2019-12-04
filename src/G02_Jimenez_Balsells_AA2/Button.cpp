#include "Button.h"

Button::Button(std::string id1, std::string id2, Vec2 p) {
	clicked = false;
	hover = false;
	pos = p;
	normalID = id1;
	hoverID = id2;
	size = Renderer::Instance()->GetTextureSize(normalID);
}

bool Button::CheckIfHover(const Vec2 &mousePos) const{
	return (mousePos.x > pos.x && mousePos.x < (pos.x + size.x) && mousePos.y < (pos.y + size.y) && mousePos.y > pos.y);
}

bool Button::IsClicked() const{
	return clicked;
}

void Button::Update(const Input &input) {
	hover = CheckIfHover(input.mouse);
	if (hover) {
		clicked = input.keyDown.at(Input::Key::LEFT_CLICK);
	}
}

void Button::Draw() const{
	if (hover) {
		Renderer::Instance()->PushImage(hoverID, { pos.x, pos.y, size.x, size.y });
	}
	else {
		Renderer::Instance()->PushImage(normalID, { pos.x, pos.y, size.x, size.y });
	}
}


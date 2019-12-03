#include "Button.h"

Button::Button(std::string id1, std::string id2, Vec2 p) {
	clicked = false;
	hover = false;
	renderer = Renderer::Instance();
	pos = p;
	normalID = id1;
	hoverID = id2;
	size = renderer->GetTextureSize(normalID);
}

bool Button::CheckIfHover(Vec2 mousePos) {
	return (mousePos.x > pos.x && mousePos.x < (pos.x + size.x) && mousePos.y < (pos.y + size.y) && mousePos.y > pos.y);
}

bool Button::IsClicked() {
	return clicked;
}

void Button::Update(const Input &input) {
	hover = CheckIfHover(input.mouse);
	if (hover) {
		clicked = input.keyDown.at(Input::Key::LEFT_CLICK);
	}
}

void Button::Draw() {
	if (hover) {
		renderer->PushImage(hoverID, { pos.x, pos.y, size.x, size.y });
	}
	else {
		renderer->PushImage(normalID, { pos.x, pos.y, size.x, size.y });
	}
}


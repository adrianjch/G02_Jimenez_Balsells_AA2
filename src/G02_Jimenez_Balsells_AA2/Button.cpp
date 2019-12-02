#include "Button.h"

Button::Button(std::string id1, std::string id2, Vec2 p) {
	clicked = false;
	hover = false;
	renderer = Renderer::Instance();
	pos = p;
	normalID = id1;
	hoverID = id2;
}

bool Button::CheckIfHover(Vec2 pos) {
	return false;
}

void Button::Update(const Input &input) {
	hover = CheckIfHover(input.mouse);
	if (hover) {
		clicked = input.keyDown.at(Input::Key::LEFT_CLICK);
	}
}

void Button::Draw() {
	if (hover) {
		renderer->PushImage(hoverID, SDL_Rect({ pos.x, pos.y, renderer->GetTextureSize(hoverID).x, renderer->GetTextureSize(hoverID).y }));
	}
	else {
		renderer->PushImage(normalID, SDL_Rect({ pos.x, pos.y, renderer->GetTextureSize(normalID).x, renderer->GetTextureSize(normalID).y }));
	}
}


#include "Ranking.h"

Ranking::Ranking() {
	state = SceneState::RUNNING;
}

void Ranking::Update(const Input &input) {
	menu.Update(input);

	if (menu.IsClicked()) {
		state = SceneState::MENU_STATE;
	}
}

void Ranking::Draw() const{
	Renderer::Instance()->Clear();
	Vec2 size = Renderer::Instance()->GetTextureSize("ranking");
	Renderer::Instance()->PushImage("ranking", { 150, 20, size.x, size.y });
	menu.Draw();
	Renderer::Instance()->Render();
}
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
	menu.Draw();
	Renderer::Instance()->Render();
}
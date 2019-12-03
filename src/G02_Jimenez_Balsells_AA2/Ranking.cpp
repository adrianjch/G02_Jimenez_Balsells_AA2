#include "Ranking.h"

Ranking::Ranking() {
	state = SceneState::RUNNING;
	renderer = renderer->Instance();
}

void Ranking::Update(const Input &input) {
	menu.Update(input);

	if (menu.IsClicked()) {
		state = SceneState::MENU_STATE;
	}
}

void Ranking::Draw() {
	renderer->Clear();
	menu.Draw();
	renderer->Render();
}
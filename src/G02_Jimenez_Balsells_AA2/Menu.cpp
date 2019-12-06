#include "Menu.h"
#include "Music.h"

Menu::Menu() {
	state = SceneState::RUNNING;
}

void Menu::Update(const Input &input) {
	play.Update(input);
	ranking.Update(input);
	sound.Update(input);
	exit.Update(input);

	if (play.IsClicked())
		state = SceneState::PLAY_STATE;
	else if (ranking.IsClicked())
		state = SceneState::RANKING_STATE;
	else if (sound.IsClicked()) {
		Music::Instance()->SetState(!Music::Instance()->GetState());
	}
	else if (exit.IsClicked())
		state = SceneState::EXIT_STATE;
}

void Menu::Draw() const{
	Renderer::Instance()->Clear();
	play.Draw();
	ranking.Draw();
	sound.Draw();
	exit.Draw();
	if (Music::Instance()->GetState()) {
		Vec2 size = Renderer::Instance()->GetTextureSize("on");
		Renderer::Instance()->PushImage("on", { SCREEN_WIDTH / 2 + 150, 3 * SCREEN_HEIGHT / 4 - 100 - size.y/2, size.x, size.y });
	}
	else {
		Vec2 size = Renderer::Instance()->GetTextureSize("off");
		Renderer::Instance()->PushImage("off", { SCREEN_WIDTH / 2 + 150, 3 * SCREEN_HEIGHT / 4 - 100 - size.y / 2, size.x, size.y });
	}

	Renderer::Instance()->Render();
}
#include "Menu.h"
#include "Music.h"

Menu::Menu() {
	state = SceneState::RUNNING;
	// Load textures and fonts
	Renderer::Instance()->LoadFont({ "buttons", "../../res/ttf/PAC-FONT.TTF", 60 });
	Renderer::Instance()->LoadTextureText("buttons", { "play normal", "PLAY", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "play hover", "play", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "ranking normal", "RANKING", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "ranking hover", "ranking", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "sound normal", "SOUND", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "sound hover", "sound", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "exit normal", "EXIT", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "exit hover", "exit", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "on", "on", {0,255,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "off", "off", {255,0,0,255}, 200, 600 });

	play.SetTextures("play normal", "play hover");
	play.SetPos({ SCREEN_WIDTH/2, SCREEN_HEIGHT/4 - 100 });
	ranking.SetTextures("ranking normal", "ranking hover");
	ranking.SetPos({ SCREEN_WIDTH/2, 2 * SCREEN_HEIGHT/4 - 100 });
	sound.SetTextures("sound normal", "sound hover");
	sound.SetPos({ SCREEN_WIDTH/2, 3 * SCREEN_HEIGHT/4 - 100 });
	exit.SetTextures("exit normal", "exit hover");
	exit.SetPos({ SCREEN_WIDTH/2, 4 * SCREEN_HEIGHT/4 - 100 });
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
	// Check if the music is active or not uses one text or the other
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
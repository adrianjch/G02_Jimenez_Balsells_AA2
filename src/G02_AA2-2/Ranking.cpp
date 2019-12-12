#include "Ranking.h"

Ranking::Ranking() {
	state = SceneState::RUNNING;
	// Load textures and fonts
	Renderer::Instance()->LoadFont({ "title", "../../res/ttf/PAC-FONT.TTF", 100 });
	Renderer::Instance()->LoadFont({ "buttons", "../../res/ttf/PAC-FONT.TTF", 60 });
	Renderer::Instance()->LoadTextureText("title", { "ranking", "ranking", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "menu normal", "MENU", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "menu hover", "menu", {255,0,0,255}, 200, 600 });
	menu.SetTextures("menu normal", "menu hover");
	menu.SetPos({ 130, SCREEN_HEIGHT - 50 });
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
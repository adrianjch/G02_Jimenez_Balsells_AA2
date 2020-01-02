#include "Ranking.h"
#include <fstream>

Ranking::Ranking() {
	state = SceneState::RUNNING;
	// Load textures and fonts
	Renderer::Instance()->LoadFont({ "title", "../../res/ttf/PAC-FONT.TTF", 100 });
	Renderer::Instance()->LoadFont({ "buttons", "../../res/ttf/PAC-FONT.TTF", 60 });
	Renderer::Instance()->LoadFont({ "players", "../../res/ttf/Gameplay.ttf", 40 });
	Renderer::Instance()->LoadTextureText("title", { "ranking", "ranking", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "menu normal", "MENU", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "menu hover", "menu", {255,0,0,255}, 200, 600 });
	menu.SetTextures("menu normal", "menu hover");
	menu.SetPos({ 130, SCREEN_HEIGHT - 50 });
	ReadRanking();
}

void Ranking::ReadRanking() {
	std::ifstream myFile;
	myFile.open("ranking.bin", std::ios::binary);
	if (myFile.is_open()) {
		myFile.read(reinterpret_cast<char*>(&numPlayers), sizeof(int)); //num of players in ranking
		for (int i = 0; i < numPlayers; i++) {
			int aux;
			myFile.read(reinterpret_cast<char*>(&aux), sizeof(int)); //length of string name
			char* name = new char[aux + 1];
			myFile.read(name, aux); // string name
			name[aux] = '\0';
			myFile.read(reinterpret_cast<char*>(&aux), sizeof(int)); // score
			Renderer::Instance()->LoadTextureText("players", { "Rank" + std::to_string(i+1), name + static_cast<std::string>(":  ") + std::to_string(aux), { 255,0,0,255 }, 200, 600 });
		}
	}
	myFile.close();
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

	for (int i = 0; i < numPlayers; i++) {
		size = Renderer::Instance()->GetTextureSize("Rank" + std::to_string(i + 1));
		Renderer::Instance()->PushImage("Rank" + std::to_string(i + 1), { 150, 150 + i *75, size.x, size.y });
	}

	menu.Draw();
	Renderer::Instance()->Render();
}
#include "Ranking.h"
#include <fstream>

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
	ReadRanking();
}

void Ranking::ReadRanking() {
	std::ifstream myFile;
	myFile.open("ranking.bin", std::ios::binary);
	if (myFile.is_open()) {
		int players;
		myFile.read(reinterpret_cast<char*>(&players), sizeof(int)); //num of players in ranking
		for (int i = 0; i < players; i++) {
			int aux;
			myFile.read(reinterpret_cast<char*>(&aux), sizeof(int)); //length of string name
			char* name = new char[aux + 1];
			myFile.read(name, aux); // string name
			name[aux] = '\0';
			myFile.read(reinterpret_cast<char*>(&aux), sizeof(int)); // score
			ranking.push_back({ name, aux });
		}
	}
	myFile.close();
	for (int i = 0; i < ranking.size(); i++)
		std::cout << ranking[i].first << "    " << ranking[i].second;
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
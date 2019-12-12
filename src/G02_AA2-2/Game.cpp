#include "Game.h"
#include "Constants.h"
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include <sstream>
#include <cmath>

Game::Game() {
	state = SceneState::START_GAME;
	// Load textures and fonts
	Renderer::Instance()->LoadFont({ "pac40", "../../res/ttf/PAC-FONT.TTF", 40 });
	Renderer::Instance()->LoadFont({ "title", "../../res/ttf/PAC-FONT.TTF", 100 });
	Renderer::Instance()->LoadFont({ "buttons", "../../res/ttf/PAC-FONT.TTF", 60 });
	Renderer::Instance()->LoadFont({ "hud", "../../res/ttf/Gameplay.ttf", 55 });
	Renderer::Instance()->LoadTexture("spritesheet", "../../res/img/PacManSpritesheet.png");
	Renderer::Instance()->LoadTextureText("pac40", { "press to play", "PrEsS sPaCe To StArT", {255,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("pac40", { "press to continue", "PrEsS sPaCe To CoNtInUe", {255,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("title", { "stop", "StOp", {255,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("pac40", { "sound: normal", "SOUND:", {255,255,255,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("pac40", { "sound: hover", "sound:", {255,255,255,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "on", "on", {0,255,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("buttons", { "off", "off", {255,0,0,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "0", "0", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "1", "1", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "2", "2", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "3", "3", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "4", "4", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "5", "5", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "6", "6", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "7", "7", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "8", "8", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "9", "9", {0,0 ,0 ,255}, 200, 600 });
	Renderer::Instance()->LoadTextureText("hud", { "X", "X", {0,0 ,0 ,255}, 200, 600 });
	// Load sounds
	Music::Instance()->LoadMusic("waka waka", "../../res/au/pacman_waka_waka.mp3");
	Music::Instance()->LoadMusic("begin", "../../res/au/pacman_beginning.mp3");
	Music::Instance()->LoadMusic("death", "../../res/au/pacman_death.mp3");
	// XML
	std::ifstream file("../../res/files/config.xml");
	if (file.is_open()) {
		rapidxml::xml_document<> doc;
		std::stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		std::string content(buffer.str());
		doc.parse<0>(&content[0]);

		rapidxml::xml_node<> *pRoot = doc.first_node();
		// Set map size
		map.SetSize({ std::stoi(pRoot->first_node("Positions")->first_attribute("x")->value()),
					  std::stoi(pRoot->first_node("Positions")->first_attribute("y")->value()) });
		// Set player position
		player.SetInitialPos({ std::stoi(pRoot->first_node("Positions")->first_node("Player")->first_attribute("x")->value()) - 1,
							   std::stoi(pRoot->first_node("Positions")->first_node("Player")->first_attribute("y")->value()) - 1 });
		// Set blinky position
		blinky.SetInitialPos({ std::stoi(pRoot->first_node("Positions")->first_node("Blinky")->first_attribute("x")->value()) - 1,
							   std::stoi(pRoot->first_node("Positions")->first_node("Blinky")->first_attribute("y")->value()) - 1 });
		// Set inky position
		inky.SetInitialPos({ std::stoi(pRoot->first_node("Positions")->first_node("Inky")->first_attribute("x")->value()) - 1,
							 std::stoi(pRoot->first_node("Positions")->first_node("Inky")->first_attribute("y")->value()) - 1 });
		// Set clyde position
		clyde.SetInitialPos({ std::stoi(pRoot->first_node("Positions")->first_node("Clyde")->first_attribute("x")->value()) - 1,
							  std::stoi(pRoot->first_node("Positions")->first_node("Clyde")->first_attribute("y")->value()) - 1 });
		// Set power ups positions
		int counter = 0;
		for (rapidxml::xml_node<> *pNode = pRoot->first_node("Positions")->first_node("PowerUps")->first_node("Power"); pNode; pNode = pNode->next_sibling()) {
			map.SetCell({ std::stoi(pNode->first_attribute("x")->value()) - 1, std::stoi(pNode->first_attribute("y")->value()) - 1 }, Map::Cell::POWER_UP);
			counter++;
		}
		// Set wall positions
		for (rapidxml::xml_node<> *pNode = pRoot->first_node("Map")->first_node("Wall"); pNode; pNode = pNode->next_sibling()) {
			map.SetCell({ std::stoi(pNode->first_attribute("x")->value()) - 1, std::stoi(pNode->first_attribute("y")->value()) - 1 }, Map::Cell::WALL);
			counter++;
		}

		// Set "empty" cells
		map.SetCell({ player.GetInitialPos().x / CELL_SIZE,player.GetInitialPos().y / CELL_SIZE }, Map::Cell::NONE);
		map.SetCell({ blinky.GetInitialPos().x / CELL_SIZE, blinky.GetInitialPos().y / CELL_SIZE }, Map::Cell::NONE);
		map.SetCell({ inky.GetInitialPos().x / CELL_SIZE,inky.GetInitialPos().y / CELL_SIZE }, Map::Cell::NONE);
		map.SetCell({ clyde.GetInitialPos().x / CELL_SIZE, clyde.GetInitialPos().y / CELL_SIZE }, Map::Cell::NONE);

		// Set the number of coins that the map should have
		map.SetCoinCounter(map.GetSize().x * map.GetSize().y - 4 - counter);

		doc.clear();
	}

	sound.SetTextures("sound: normal", "sound: hover");
	sound.SetPos({ SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 + 70 });
	Music::Instance()->PlayMusic("begin", 1);
}

void Game::Update(const Input &input) {
	switch (Scene::GetState()) {
	case SceneState::START_GAME:
		// While the beginging sound is playing the game doesn't accept input
		if (!Music::Instance()->IsPlaying()) {
			if (input.key.at(Input::Key::SPACE)) {
				state = SceneState::RUNNING;
				fruitTimer = clock();
			}
			else if (input.key.at(Input::Key::ESCAPE)) {
				state = SceneState::MENU_STATE;
			}
		}
		break;
	case SceneState::RUNNING:
		if (input.key.at(Input::Key::P)) {
			state = SceneState::PAUSE;
		}
		player.Update(input, map);


		// Check Fruit collisions and fruit timer
		if (fruit == nullptr) {
			if (((clock() - fruitTimer) / (float)CLOCKS_PER_SEC >= 10)) {
				fruit = new Fruit(player.GetInitialPos());	////
			}
		}
		else {
			if ((sqrt((pow(player.GetPixelPos().x - fruit->GetInitialPos().x, 2) + pow(player.GetPixelPos().y - fruit->GetInitialPos().y, 2))) < 25)) {
				switch (fruit->GetType()) {
					case Fruit::FruitType::CHERRY:
						player.SetScore(Fruit::FruitType::CHERRY);
						break;
					case Fruit::FruitType::SRTRAWBERRY:
						player.SetScore(Fruit::FruitType::SRTRAWBERRY);
						break;
					case Fruit::FruitType::ORANGE:
						player.SetScore(Fruit::FruitType::ORANGE);
						break;
				}
				fruitTimer = clock();
				delete fruit;
				fruit = nullptr;
			}
		}

		// If the player isn't dead update the enemies and check the collisions
		if (player.GetState() != Player::State::DEAD && player.GetState() != Player::State::RESET) {
			inky.Update(input, map);
			clyde.Update(input, map);

			if ((sqrt((pow(player.GetPixelPos().x - inky.GetPixelPos().x, 2) + pow(player.GetPixelPos().y - inky.GetPixelPos().y, 2))) < 25) ||
				(sqrt((pow(player.GetPixelPos().x - clyde.GetPixelPos().x, 2) + pow(player.GetPixelPos().y - clyde.GetPixelPos().y, 2))) < 25) ||
				(sqrt((pow(player.GetPixelPos().x - blinky.GetPixelPos().x, 2) + pow(player.GetPixelPos().y - blinky.GetPixelPos().y, 2))) < 25)) {

				player.Dead();
			}
		}

		// After the player has been killed and the animation done the players the game gets reseted
		if (player.GetState() == Player::State::RESET) {
			inky.Reset();
			clyde.Reset();
			player.Reset();

			if (player.GetLives() <= 0)
				state = SceneState::GAME_OVER;
			else {
				state = SceneState::START_GAME;
				if (fruit != nullptr) {
					delete fruit;
					fruit = nullptr;
				}
			}
		}

		// If the player collects all the coins the game ends
		if (map.GetCoinCounter() <= 0) {
			state = SceneState::GAME_OVER;
			Music::Instance()->PauseMusic();
		}
		break;
	case SceneState::GAME_OVER:
		state = SceneState::RANKING_STATE;
		if (fruit != nullptr) {
			delete fruit;
			fruit = nullptr;
		}
		break;
	case SceneState::PAUSE:
		if (input.key.at(Input::Key::ESCAPE)) {
			state = SceneState::MENU_STATE;
			if (fruit != nullptr) {
				delete fruit;
				fruit = nullptr;
			}
		}
		else if (input.key.at(Input::Key::SPACE)) {
			state = SceneState::RUNNING;
		}

		// Checks if the music is playing and then stops it
		if (Music::Instance()->IsPlaying()) {
			Music::Instance()->PauseMusic();
		}
		sound.Update(input);

		// If the button has been clicked changes de music state
		if (sound.IsClicked()) {
			Music::Instance()->SetState(!Music::Instance()->GetState());
		}
	}
}

void Game::Draw() const {
	Renderer::Instance()->Clear();
	switch (Scene::GetState()) {
	case SceneState::START_GAME: {
		map.Draw();
		if (fruit != nullptr)
			fruit->Draw();
		blinky.Draw();
		inky.Draw();
		clyde.Draw();
		player.Draw();
		hud.Draw(player);
		Renderer::Instance()->PushSprite("spritesheet", { 0, 996, 128, 128 }, { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
		Vec2 size = Renderer::Instance()->GetTextureSize("press to play");
		Renderer::Instance()->PushImage("press to play", { SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 - 50, size.x, size.y });
		break;
	}
	case SceneState::RUNNING:
		map.Draw();
		if(fruit != nullptr)
			fruit->Draw();
		blinky.Draw();
		inky.Draw();
		clyde.Draw();
		player.Draw();
		hud.Draw(player);
		break;
	case SceneState::GAME_OVER:
		break;
	case SceneState::PAUSE: {
		map.Draw();
		if (fruit != nullptr)
			fruit->Draw();
		blinky.Draw();
		inky.Draw();
		clyde.Draw();
		player.Draw();
		hud.Draw(player);
		Renderer::Instance()->PushSprite("spritesheet", { 0, 996, 128, 128 }, { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
		Vec2 size = Renderer::Instance()->GetTextureSize("stop");
		Renderer::Instance()->PushImage("stop", { 220, 50, size.x, size.y });
		size = Renderer::Instance()->GetTextureSize("press to continue");
		Renderer::Instance()->PushImage("press to continue", { 20, 200, size.x, size.y });
		sound.Draw();
		if (Music::Instance()->GetState()) {
			size = Renderer::Instance()->GetTextureSize("on");
			Renderer::Instance()->PushImage("on", { 470, 390, size.x, size.y });
		}
		else {
			size = Renderer::Instance()->GetTextureSize("off");
			Renderer::Instance()->PushImage("off", { 470, 390, size.x, size.y });
		}
		break;
	}
	}
	Renderer::Instance()->Render();
}
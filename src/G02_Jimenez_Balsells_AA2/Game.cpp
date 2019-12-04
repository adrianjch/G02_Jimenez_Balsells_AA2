#include "Game.h"
#include "Constants.h"
#include <sstream>
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"

Game::Game() {
	state = SceneState::START_GAME;
	renderer = renderer->Instance();
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
		map.SetCell(player.GetInitialPos(), Map::Cell::NONE);
		map.SetCell(blinky.GetInitialPos(), Map::Cell::NONE);
		map.SetCell(inky.GetInitialPos(), Map::Cell::NONE);
		map.SetCell(clyde.GetInitialPos(), Map::Cell::NONE);

		map.SetCoinCounter(map.GetSize().x * map.GetSize().y - 4 - counter);

		doc.clear();
	}
}

void Game::Update(const Input &input) {
	switch (Scene::GetState()) {
	case SceneState::START_GAME:
		if (input.key.at(Input::Key::SPACE)) {
			state = SceneState::RUNNING;
		}
		else if (input.key.at(Input::Key::ESCAPE)) {
			state = SceneState::MENU_STATE;
		}
		break;
	case SceneState::RUNNING:
		if (input.key.at(Input::Key::P)) {
			state = SceneState::PAUSE;
		}
		player.Update(input, map);
		inky.Update(input, map);
		clyde.Update(input, map);

		if (map.GetCoinCounter() <= 0 || player.GetLives() <= 0)
			state = SceneState::GAME_OVER;

		break;
	case SceneState::GAME_OVER:
		state = SceneState::RANKING_STATE;
		break;
	case SceneState::PAUSE:
		if(input.key.at(Input::Key::ESCAPE)) {
			state = SceneState::MENU_STATE;
		}
		else if (input.key.at(Input::Key::SPACE)) {
			state = SceneState::RUNNING;
		}
	}
}

void Game::Draw() {
	renderer->Clear();
	switch (Scene::GetState()) {
		case SceneState::START_GAME:
			map.Draw();
			blinky.Draw();
			inky.Draw();
			clyde.Draw();
			fruit->Draw();
			player.Draw();
			hud.Draw(player);
			renderer->PushSprite("spritesheet", { 0, 996, 128, 128 }, { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
			renderer->PushImage("press to play", { SCREEN_WIDTH/2 - 400, SCREEN_HEIGHT/2, renderer->GetTextureSize("press to play").x, renderer->GetTextureSize("press to play").y });
			break;
		case SceneState::RUNNING:
			map.Draw();
			blinky.Draw();
			inky.Draw();
			clyde.Draw();
			fruit->Draw();
			player.Draw();
			hud.Draw(player);
			break;
		case SceneState::GAME_OVER:

			break;
		case SceneState::PAUSE:
			sound.Draw();
			break;
	}
	renderer->Render();
}
#pragma once
#include "Clyde.h"

Clyde::Clyde() {
	actualMovement = futureMovement = Movement::RIGHT;
	spriteNumber = 4;
}

void Clyde::Update(const Input &input, const Map &map) {

	if (state == State::DEAD) {
		deadTimer += static_cast<float>(1.0f / MAX_FRAMERATE);
		if (deadTimer >= 2.0f)
			state = State::NORMAL;
	}
	else if (state == State::NORMAL){
		if (input.keyDown.at(Input::Key::W) || input.keyDown.at(Input::Key::UP))
			futureMovement = Movement::DOWN;
		else if (input.keyDown.at(Input::Key::A) || input.keyDown.at(Input::Key::LEFT))
			futureMovement = Movement::RIGHT;
		else if (input.keyDown.at(Input::Key::S) || input.keyDown.at(Input::Key::DOWN))
			futureMovement = Movement::UP;
		else if (input.keyDown.at(Input::Key::D) || input.keyDown.at(Input::Key::RIGHT))
			futureMovement = Movement::LEFT;
		Move(map);
		frameCounter++;
	}
	else if (state == State::SCARED) {
		if (input.keyDown.at(Input::Key::W) || input.keyDown.at(Input::Key::UP))
			futureMovement = Movement::DOWN;
		else if (input.keyDown.at(Input::Key::A) || input.keyDown.at(Input::Key::LEFT))
			futureMovement = Movement::RIGHT;
		else if (input.keyDown.at(Input::Key::S) || input.keyDown.at(Input::Key::DOWN))
			futureMovement = Movement::UP;
		else if (input.keyDown.at(Input::Key::D) || input.keyDown.at(Input::Key::RIGHT))
			futureMovement = Movement::LEFT;
		if (moved) {
			Move(map);
			frameCounter++;
		}
		moved = !moved;
	}
}

void Clyde::Move(const Map &map) {
	// Checks if the enemy can move to the position that he wants
	// If he's able to move the actualMovement will be Updated
	switch (actualMovement) {
	case Movement::UP:
		switch (futureMovement) {
		case Movement::DOWN:
			actualMovement = Movement::DOWN;
			break;
		case Movement::LEFT:
			if (pixelPos.y % CELL_SIZE == 0 && map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::LEFT;
			}
			break;
		case Movement::RIGHT:
			if (pixelPos.y % CELL_SIZE == 0 && map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::RIGHT;
			}
			break;
		}
		break;
	case Movement::DOWN:
		switch (futureMovement) {
		case Movement::UP:
			actualMovement = Movement::UP;
			break;
		case Movement::LEFT:
			if (pixelPos.y % CELL_SIZE == 0 && map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::LEFT;
			}
			break;
		case Movement::RIGHT:
			if (pixelPos.y % CELL_SIZE == 0 && map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::RIGHT;
			}
			break;
		}
		break;
	case Movement::LEFT:
		switch (futureMovement) {
		case Movement::UP:
			if (pixelPos.x % CELL_SIZE == 0 && map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::UP;
			}
			break;
		case Movement::DOWN:
			if (pixelPos.x % CELL_SIZE == 0 && map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::DOWN;
			}
			break;
		case Movement::RIGHT:
			actualMovement = Movement::RIGHT;
			break;
		}
		break;
	case Movement::RIGHT:
		switch (futureMovement) {
		case Movement::UP:
			if (pixelPos.x % CELL_SIZE == 0 && map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::UP;
			}
			break;
		case Movement::DOWN:
			if (pixelPos.x % CELL_SIZE == 0 && map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
				actualMovement = Movement::DOWN;
			}
			break;
		case Movement::LEFT:
			actualMovement = Movement::LEFT;
			break;
		}
		break;
	}

	// When the player kwnow where he will move check again if he can move and update his pos
	switch (actualMovement) {
	case Movement::UP:
		if (map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL)
			pixelPos.y -= 1;
		// Checks the frame rate and if the number of frames per sprite is bigger than the limit change the sprite
		if (frameCounter >= MAX_FRAME) {
			switch (state) {
				case State::NORMAL:
					if (spriteNumber == 0)
						spriteNumber = 1;
					else
						spriteNumber = 0;
					frameCounter = 0;
					break;

				case State::SCARED:
					spriteNumber++;
					spriteNumber = spriteNumber % 4;
					frameCounter = 0;
					break;
			}
		}
		break;
	case Movement::DOWN:
		if (map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL)
			pixelPos.y += 1;
		if (frameCounter >= MAX_FRAME) {
			switch (state) {
				case State::NORMAL:
					if (spriteNumber == 2)
						spriteNumber = 3;
					else
						spriteNumber = 2;
					frameCounter = 0;
					break;

				case State::SCARED:
					spriteNumber++;
					spriteNumber = spriteNumber % 4;
					frameCounter = 0;
					break;
			}
		}
		break;
	case Movement::LEFT:
		if (map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL)
			pixelPos.x -= 1;
		if (frameCounter >= MAX_FRAME) {
			switch (state) {
				case State::NORMAL:
					if (spriteNumber == 6)
						spriteNumber = 7;
					else
						spriteNumber = 6;
					frameCounter = 0;
					break;

				case State::SCARED:
					spriteNumber++;
					spriteNumber = spriteNumber % 4;
					frameCounter = 0;
					break;
			}
		}
		break;
	case Movement::RIGHT:
		if (map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) 
			pixelPos.x += 1;
		if (frameCounter >= MAX_FRAME) {
			switch (state) {
			case State::NORMAL:
				if (spriteNumber == 4)
					spriteNumber = 5;
				else
					spriteNumber = 4;
				frameCounter = 0;
				break;

			case State::SCARED:
				spriteNumber++;
				spriteNumber = spriteNumber % 4;
				frameCounter = 0;
				break;
			}
		}
		break;
	}

	// Checks if the player crosses the map limits and in case he does it he reapers in oposit part of he map
	if (pixelPos.x <= -CELL_SIZE)
		pixelPos.x = 699;
	else if (pixelPos.x >= 700)
		pixelPos.x = -CELL_SIZE + 1;

	if (pixelPos.y <= -CELL_SIZE)
		pixelPos.y = 699;
	else if (pixelPos.y >= 700)
		pixelPos.y = -CELL_SIZE + 1;
}

void Clyde::Draw() const{
	switch (state) {
		case State::SCARED:
			Renderer::Instance()->PushSprite("spritesheet", { spriteNumber * 128, 512, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
			break;
		case State::NORMAL:
			Renderer::Instance()->PushSprite("spritesheet", { spriteNumber * 128, 384, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
			break;
	}
}

void Clyde::Reset() {
	pixelPos = initialPos;
	actualMovement = futureMovement = Movement::RIGHT;
	spriteNumber = 4;
	frameCounter = 0;
}
#pragma once
#include "Blinky.h"

Blinky::Blinky() {
	actualMovement = static_cast<Movement>(rand() % 4);
	spriteNumber = static_cast<int>(actualMovement) * 2;
}

void Blinky::Update(const Map &map) {
	if (state == State::DEAD) {
		deadTimer += static_cast<float>(1.0f / MAX_FRAMERATE);
		if (deadTimer >= 2.0f)
			state = State::NORMAL;
	}
	else if(state == State::NORMAL){
		Move(map);
		frameCounter++;
	}
	else if (state == State::SCARED) {
		if (moved) {
			Move(map);
			frameCounter++;
		}
		moved = !moved;
	}
}

void Blinky::Move(const Map &map) {
	
	if (pixelPos.x % CELL_SIZE == 0 && pixelPos.y % CELL_SIZE == 0) {
		std::vector<Movement> move;

		switch (actualMovement)
		{
			case Movement::RIGHT:
				// UP
				if (map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::UP);
				// RIGHT
				if (map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::RIGHT);
				// DOWN
				if (map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::DOWN);
				break;
			case Movement::LEFT:
				// UP
				if (map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::UP);
				// LEFT
				if (map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::LEFT);
				// DOWN
				if (map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::DOWN);
				break;
			case Movement::UP:
				// UP
				if (map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::UP);
				// LEFT
				if (map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::LEFT);
				// RIGHT
				if (map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::RIGHT);
				break;
			case Movement::DOWN:
				// DOWN
				if (map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::DOWN);
				// LEFT
				if (map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::LEFT);
				// RIGHT
				if (map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL)
					move.push_back(Movement::RIGHT);
				break;
		}		

		actualMovement = move[rand() % move.size()];
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

void Blinky::Draw() const{
	switch (state) {
		case State::SCARED:
			Renderer::Instance()->PushSprite("spritesheet", { spriteNumber * 128, 512, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
			break;
		case State::NORMAL:
			Renderer::Instance()->PushSprite("spritesheet", { spriteNumber * 128, 128, 128, 128 }, { pixelPos.x, pixelPos.y, 35, 35 });
			break;
	}
}

void Blinky::Reset() {
	pixelPos = initialPos;
	actualMovement = static_cast<Movement>(rand() % 4);
	spriteNumber = static_cast<int>(actualMovement) * 2;
	frameCounter = 0;
}
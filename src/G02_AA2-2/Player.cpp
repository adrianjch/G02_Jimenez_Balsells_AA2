#pragma once
#include "Player.h"

Player::Player() {
	actualMovement = futureMovement = Movement::LEFT;
	state = State::NORMAL;
	spriteNumber = 6;
	frameCounter = 0;
	score = 0;
	lives = 3;
}

Vec2 Player::GetInitialPos() const{
	return initialPos;
}

Vec2 Player::GetPixelPos() const{
	return pixelPos;
}

int Player::GetScore() const{
	return score;
}

int Player::GetLives() const{
	return lives;
}

Player::State Player::GetState() const{
	return state;
}

void Player::SetInitialPos(const Vec2 &_initialPos) {
	initialPos = { _initialPos.x*CELL_SIZE, _initialPos.y*CELL_SIZE };
	pixelPos = initialPos;
}

void Player::SetScore(const int &_score) {
	if (_score > 9999)
		score = 9999;
	else
		score = _score;
}

void Player::SetLives(const int &_lives) {
	lives = _lives;
}

void Player::SetState(const State &_state) {
	state = _state;
}

void Player::Update(const Input &input, Map &map) {
	// Checks if the player is dead
	if (state != State::DEAD && state != State::RESET) {
		if (input.keyDown.at(Input::Key::W) || input.keyDown.at(Input::Key::UP))
			futureMovement = Movement::UP;
		else if (input.keyDown.at(Input::Key::A) || input.keyDown.at(Input::Key::LEFT))
			futureMovement = Movement::LEFT;
		else if (input.keyDown.at(Input::Key::S) || input.keyDown.at(Input::Key::DOWN))
			futureMovement = Movement::DOWN;
		else if (input.keyDown.at(Input::Key::D) || input.keyDown.at(Input::Key::RIGHT))
			futureMovement = Movement::RIGHT;

		Move(map);

		// Checks if there's a coin in the current cell
		if (map.GetCell({ pixelPos.x / CELL_SIZE, pixelPos.y / CELL_SIZE }) == Map::Cell::POINT) {
			//  Checks is the player is in the center of the cell to collect the coin
			if ((actualMovement == Movement::LEFT || actualMovement == Movement::RIGHT) && (pixelPos.x % CELL_SIZE == 0)) {
				map.SetCell({ pixelPos.x / CELL_SIZE, pixelPos.y / CELL_SIZE }, Map::Cell::NONE);
				SetScore(score + 1);
				map.SetCoinCounter(map.GetCoinCounter() - 1);
			}
			else if ((actualMovement == Movement::UP || actualMovement == Movement::DOWN) && (pixelPos.y % CELL_SIZE == 0)) {
				map.SetCell({ pixelPos.x / CELL_SIZE, pixelPos.y / CELL_SIZE }, Map::Cell::NONE);
				SetScore(score + 1);
				map.SetCoinCounter(map.GetCoinCounter() - 1);
			}
		}
		// Checks if there's a power up in the current cell
		if (map.GetCell({ pixelPos.x / CELL_SIZE, pixelPos.y / CELL_SIZE }) == Map::Cell::POWER_UP) {
			//  Checks is the player is in the center of the cell to collect the power up
			if ((actualMovement == Movement::LEFT || actualMovement == Movement::RIGHT) && (pixelPos.x % CELL_SIZE == 0)) {
				map.SetCell({ pixelPos.x / CELL_SIZE, pixelPos.y / CELL_SIZE }, Map::Cell::NONE);
				// isEmpowered = true;
				SetScore(score + 20);

			}
			else if ((actualMovement == Movement::UP || actualMovement == Movement::DOWN) && (pixelPos.y % CELL_SIZE == 0)) {
				map.SetCell({ pixelPos.x / CELL_SIZE, pixelPos.y / CELL_SIZE }, Map::Cell::NONE);
				// isEmpowered = true;
				SetScore(score + 20);
			}
		}
	}
	// Checks if the player is dead
	else if(state == State::DEAD) {
		// Updates the dead animation until its finished
		if (frameCounter > MAX_FRAME_DEAD) {
			if (spriteNumber == 11) {
				state = State::RESET;
			}
			frameCounter = 0;
			spriteNumber++;
		}
	}
	frameCounter++;
	
	// std::cout << cellPos.x << "," << cellPos.y << "  " << pixelPos.x << "," << pixelPos.y << (int)actualMovement << (int)futureMovement << std::endl;
}

void Player::Move(const Map &map) {
	// Checks if the player can move to the position that he wants
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

	// Updates the sound of the player
	// We only update the sound once after the game has started
	if (!Music::Instance()->IsPlaying()) {
		Music::Instance()->PlayMusic("waka waka", -1);
	}

	// When the player kwnow where he will move check again if he can move and update his pos
	switch (actualMovement) {
	case Movement::UP:
		if (map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
			pixelPos.y -= 1;
			// If the player is moving we check is the sound is paused and we update it
			if (Music::Instance()->IsPaused()) {
				Music::Instance()->ResumeMusic();
			}

			// Checks the frame rate and if the number of frames per sprite is bigger than the limit change the sprite
			if (frameCounter >= MAX_FRAME_NORMAL) {
				if (spriteNumber == 0)
					spriteNumber = 1;
				else
					spriteNumber = 0;
				frameCounter = 0;
			}
		}
		else {
			// If the player is not moving we pause de sound
			Music::Instance()->PauseMusic();
		}
		break;
	case Movement::DOWN:
		if (map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
			pixelPos.y += 1;

			if (Music::Instance()->IsPaused()) {
				Music::Instance()->ResumeMusic();
			}

			if (frameCounter >= MAX_FRAME_NORMAL) {
				if (spriteNumber == 2)
					spriteNumber = 3;
				else
					spriteNumber = 2;
				frameCounter = 0;
			}
		}
		else {
			Music::Instance()->PauseMusic();
		}
		break;
	case Movement::LEFT:
		if (map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
			pixelPos.x -= 1;

			if (Music::Instance()->IsPaused()) {
				Music::Instance()->ResumeMusic();
			}

			if (frameCounter >= MAX_FRAME_NORMAL) {
				if (spriteNumber == 6)
					spriteNumber = 7;
				else
					spriteNumber = 6;
				frameCounter = 0;
			}
		}
		else {
			Music::Instance()->PauseMusic();
		}
		break;
	case Movement::RIGHT:
		if (map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
			pixelPos.x += 1;

			if (Music::Instance()->IsPaused()) {
				Music::Instance()->ResumeMusic();
			}

			if (frameCounter >= MAX_FRAME_NORMAL) {
				if (spriteNumber == 4)
					spriteNumber = 5;
				else
					spriteNumber = 4;
				frameCounter = 0;
			}
		}
		else {
			Music::Instance()->PauseMusic();
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

void Player::Draw() const{
	switch (state) {
		case State::NORMAL:
			Renderer::Instance()->PushSprite("spritesheet", { spriteNumber * 128, 0, 128, 128 }, { pixelPos.x, pixelPos.y, CELL_SIZE, CELL_SIZE });
			break;
		case State::DEAD:
			if (spriteNumber < 4) 
				Renderer::Instance()->PushSprite("spritesheet", { spriteNumber * 128 + 512, 512, 128, 128 }, { pixelPos.x, pixelPos.y, CELL_SIZE, CELL_SIZE });
			else 
				Renderer::Instance()->PushSprite("spritesheet", { (spriteNumber - 4) * 128, 640, 128, 128 }, { pixelPos.x, pixelPos.y, CELL_SIZE, CELL_SIZE });
			break;
		case State::POWER:
			break;
	}
}

void Player::Reset() {
	pixelPos = initialPos;
	actualMovement = futureMovement = Movement::LEFT;
	SetLives(lives - 1);
	state = State::NORMAL;
	spriteNumber = 6;
	frameCounter = 0;
}

void Player::Dead() {
	state = State::DEAD;
	Music::Instance()->PauseMusic();
	Music::Instance()->PlayMusic("death", 1);
	spriteNumber = 0;
	frameCounter = 0;
}
#pragma once
#include "Player.h"

Player::Player() {
	actualMovement = futureMovement = Movement::LEFT;
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

bool Player::IsEmpowered() const{
	return isEmpowered;
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

void Player::SetEmpowered(const bool &empowered) {
	isEmpowered = empowered;
}

void Player::Update(const Input &input, Map &map) {
	if (input.keyDown.at(Input::Key::W) || input.keyDown.at(Input::Key::UP))
		futureMovement = Movement::UP;
	else if (input.keyDown.at(Input::Key::A) || input.keyDown.at(Input::Key::LEFT))
		futureMovement = Movement::LEFT;
	else if (input.keyDown.at(Input::Key::S) || input.keyDown.at(Input::Key::DOWN))
		futureMovement = Movement::DOWN;
	else if (input.keyDown.at(Input::Key::D) || input.keyDown.at(Input::Key::RIGHT))
		futureMovement = Movement::RIGHT;

	Move(map);

	if (map.GetCell({ pixelPos.x / CELL_SIZE, pixelPos.y / CELL_SIZE }) == Map::Cell::POINT) {
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

	if (map.GetCell({ pixelPos.x / CELL_SIZE, pixelPos.y / CELL_SIZE }) == Map::Cell::POWER_UP) {
		if ((actualMovement == Movement::LEFT || actualMovement == Movement::RIGHT) && (pixelPos.x % CELL_SIZE == 10)) {
			map.SetCell({ pixelPos.x / CELL_SIZE, pixelPos.y / CELL_SIZE }, Map::Cell::NONE);
			// isEmpowered = true;
			
		}
		else if ((actualMovement == Movement::UP || actualMovement == Movement::DOWN) && (pixelPos.y % CELL_SIZE == 10)) {
			map.SetCell({ pixelPos.x / CELL_SIZE, pixelPos.y / CELL_SIZE }, Map::Cell::NONE);
			// isEmpowered = true;
		}
	}

	frameCounter++;
	
	// std::cout << cellPos.x << "," << cellPos.y << "  " << pixelPos.x << "," << pixelPos.y << (int)actualMovement << (int)futureMovement << std::endl;
}

void Player::Move(const Map &map) {
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

	switch (actualMovement) {
	case Movement::UP:
		if (map.GetCell({ pixelPos.x / CELL_SIZE, ((700 + pixelPos.y - 1) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
			pixelPos.y -= 1;
			if (frameCounter >= MAX_FRAME) {
				if (spriteNumber == 0)
					spriteNumber = 1;
				else
					spriteNumber = 0;
				frameCounter = 0;
			}
		}
		break;
	case Movement::DOWN:
		if (map.GetCell({ pixelPos.x / CELL_SIZE, ((pixelPos.y + CELL_SIZE) % 700) / CELL_SIZE }) != Map::Cell::WALL) {
			pixelPos.y += 1;
			if (frameCounter >= MAX_FRAME) {
				if (spriteNumber == 2)
					spriteNumber = 3;
				else
					spriteNumber = 2;
				frameCounter = 0;
			}
		}
		break;
	case Movement::LEFT:
		if (map.GetCell({ ((700 + pixelPos.x - 1) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
			pixelPos.x -= 1;
			if (frameCounter >= MAX_FRAME) {
				if (spriteNumber == 6)
					spriteNumber = 7;
				else
					spriteNumber = 6;
				frameCounter = 0;
			}
		}
		break;
	case Movement::RIGHT:
		if (map.GetCell({ ((pixelPos.x + CELL_SIZE) % 700) / CELL_SIZE, pixelPos.y / CELL_SIZE }) != Map::Cell::WALL) {
			pixelPos.x += 1;
			if (frameCounter >= MAX_FRAME) {
				if (spriteNumber == 4)
					spriteNumber = 5;
				else
					spriteNumber = 4;
				frameCounter = 0;
			}
		}
		break;
	}

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
	Renderer::Instance()->PushSprite("spritesheet", { spriteNumber*128, 0, 128, 128 }, { pixelPos.x, pixelPos.y, CELL_SIZE, CELL_SIZE });
}

void Player::Dead() {
	pixelPos = initialPos;
	SetLives(lives - 1);
}
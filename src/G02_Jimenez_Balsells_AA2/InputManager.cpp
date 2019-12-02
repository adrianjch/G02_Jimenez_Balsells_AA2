#include "InputManager.h"
#include "SDL.h"

void InputManager::ReadInput() {
	//restart keyDown and keyUp
	for (int i = 0; i < static_cast<int>(Input::Key::COUNTER); i++) {
		input.keyDown[static_cast<Input::Key>(i)] = false;
	}
	for (int i = 0; i < static_cast<int>(Input::Key::COUNTER); i++) {
		input.keyUp[static_cast<Input::Key>(i)] = false;
	}

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_w:
						input.keyDown[Input::Key::W] = true;
						input.key[Input::Key::W] = true;
						break;
					case SDLK_a:
						input.keyDown[Input::Key::A] = true;
						input.key[Input::Key::A] = true;
						break;
					case SDLK_s:
						input.keyDown[Input::Key::S] = true;
						input.key[Input::Key::S] = true;
						break;
					case SDLK_d:
						input.keyDown[Input::Key::D] = true;
						input.key[Input::Key::D] = true;
						break;
					case SDLK_LEFT:
						input.keyDown[Input::Key::LEFT] = true;
						input.key[Input::Key::LEFT] = true;
						break;
					case SDLK_RIGHT:
						input.keyDown[Input::Key::RIGHT] = true;
						input.key[Input::Key::RIGHT] = true;
						break;
					case SDLK_UP:
						input.keyDown[Input::Key::UP] = true;
						input.key[Input::Key::UP] = true;
						break;
					case SDLK_DOWN:
						input.keyDown[Input::Key::DOWN] = true;
						input.key[Input::Key::DOWN] = true;
						break;
					case SDLK_SPACE:
						input.keyDown[Input::Key::SPACE] = true;
						input.key[Input::Key::SPACE] = true;
						break;
					case SDLK_ESCAPE:
						input.keyDown[Input::Key::ESCAPE] = true;
						input.key[Input::Key::ESCAPE] = true;
						break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym) {
					case SDLK_w:
						input.keyUp[Input::Key::W] = true;
						input.key[Input::Key::W] = false;
						break;
					case SDLK_a:
						input.keyUp[Input::Key::A] = true;
						input.key[Input::Key::A] = false;
						break;
					case SDLK_s:
						input.keyUp[Input::Key::S] = true;
						input.key[Input::Key::S] = false;
						break;
					case SDLK_d:
						input.keyUp[Input::Key::D] = true;
						input.key[Input::Key::D] = false;
						break;
					case SDLK_LEFT:
						input.keyUp[Input::Key::LEFT] = true;
						input.key[Input::Key::LEFT] = false;
						break;
					case SDLK_RIGHT:
						input.keyUp[Input::Key::RIGHT] = true;
						input.key[Input::Key::RIGHT] = false;
						break;
					case SDLK_UP:
						input.keyUp[Input::Key::UP] = true;
						input.key[Input::Key::UP] = false;
						break;
					case SDLK_DOWN:
						input.keyUp[Input::Key::DOWN] = true;
						input.key[Input::Key::DOWN] = false;
						break;
					case SDLK_SPACE:
						input.keyUp[Input::Key::SPACE] = true;
						input.key[Input::Key::SPACE] = false;
						break;
					case SDLK_ESCAPE:
						input.keyUp[Input::Key::ESCAPE] = true;
						input.key[Input::Key::ESCAPE] = false;
						break;
				}
				break;
			case SDL_MOUSEMOTION:
				input.mouse.x = event.motion.x;
				input.mouse.y = event.motion.y;
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button) {
					case SDL_BUTTON_LEFT:
						input.keyDown[Input::Key::LEFT_CLICK] = true;
						input.key[Input::Key::LEFT_CLICK] = true;
						break;
					case SDL_BUTTON_RIGHT:
						input.keyDown[Input::Key::RIGHT_CLICK] = true;
						input.key[Input::Key::RIGHT_CLICK] = true;
						break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch (event.button.button) {
					case SDL_BUTTON_LEFT:
						input.keyUp[Input::Key::LEFT_CLICK] = true;
						input.key[Input::Key::LEFT_CLICK] = false;
						break;
					case SDL_BUTTON_RIGHT:
						input.keyUp[Input::Key::RIGHT_CLICK] = true;
						input.key[Input::Key::RIGHT_CLICK] = true;
						break;
				}
				break;
		}
	}
}

Input InputManager::GetInput() {
	return input;
}
#pragma once
#include <SDL_timer.h>

unsigned int GetTicks() {
	return SDL_GetTicks();
}

void Delay(const unsigned int &ms) {
	SDL_Delay(ms);
}
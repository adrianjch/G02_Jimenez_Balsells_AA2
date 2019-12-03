#pragma once
#include "Hud.h"

Hud::Hud() {
	renderer = renderer->Instance();
}

void Hud::Draw(Player p) {
	renderer->PushSprite("spritesheet", { 996, 768, 128, 128 }, { 700, 0, 200, 700 });
}
#pragma once
#include "Types.h"

class InputManager {
private:
	Input input;
public:
	void ReadInput();
	Input GetInput();
};
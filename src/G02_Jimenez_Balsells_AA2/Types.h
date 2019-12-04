#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>


struct Line {
	Line() : a(0), b(0), c(0) {};
	Line(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {};
	int a, b, c;
};

struct Rect {
	int x, y;
	int w, h;

	Rect() {};
	Rect(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {};
	//void SetPosition(Vector2 pos) { x = pos.x; y = pos.y; };
};

struct Color {
	int r, g, b, a;

	Color() {};
	Color(int _r, int _g, int _b, int _a) : r(_r), g(_g), b(_b), a(_a) {};
};

struct Font {
	std::string id;
	std::string path;
	int size;
};

struct Text {
	std::string id;
	std::string text;
	Color color;
	int w;
	int h;
};

struct Vec2 {
	int x;
	int y;

	Vec2() {};
	Vec2(int _x, int _y) : x(_x), y(_y) {};
};

struct Input {
	enum class Key { W, A, S, D, P, LEFT, RIGHT, UP, DOWN, SPACE, ESCAPE, LEFT_CLICK, RIGHT_CLICK, COUNTER };

	Input() {
		for (int i = 0; i < static_cast<int>(Key::COUNTER); i++) {
			keyDown.insert(std::pair<Key, bool>(static_cast<Key>(i), false));
			keyUp.insert(std::pair<Key, bool>(static_cast<Key>(i), false));
			key.insert(std::pair<Key, bool>(static_cast<Key>(i), false));
		}
		mouse.x = 0;
		mouse.y = 0;
	}

	std::unordered_map<Key, bool> keyDown;
	std::unordered_map<Key, bool> keyUp;
	std::unordered_map<Key, bool> key;
	Vec2 mouse;
};

enum class Movement { UP, DOWN, LEFT, RIGHT };
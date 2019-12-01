#pragma once
class Scene {
public:
	enum class SceneState { RUNNING, MENU_STATE, PAUSE, GAME_OVER, RANKING_STATE, START_GAME, PLAY_STATE, EXIT_STATE };
protected:
	SceneState state;
public:
	virtual void Update();
	virtual void Draw();
	SceneState GetState();
};
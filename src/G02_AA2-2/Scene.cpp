#include "Scene.h"
#include "Renderer.h"
#include "Music.h"

Scene::SceneState Scene::GetState() const{
	return state;
}

Scene::~Scene() {
	Renderer::Instance()->ResetMap();
	Music::Instance()->ResetMap();
}
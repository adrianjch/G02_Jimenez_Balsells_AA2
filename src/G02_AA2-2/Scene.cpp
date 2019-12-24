#include "Scene.h"

Scene::SceneState Scene::GetState() const{
	return state;
}

Scene::~Scene() {
	Renderer::Instance()->ResetMap();
}
#pragma once
#include "Scene.h"
#include <memory.h>

class SceneManager
{
public:
	SceneManager() = default;
	SceneManager(std::unique_ptr<Scene>&& scene);

	void setCurrentScene(std::unique_ptr<Scene>&& scene);
	void draw();
	void update();

private:
	std::unique_ptr<Scene> m_currentScene = nullptr;
};


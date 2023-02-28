#include "SceneManager.h"

SceneManager::SceneManager(std::unique_ptr<Scene>&& scene)
{
	m_currentScene = std::move(scene);
}

void SceneManager::setCurrentScene(std::unique_ptr<Scene>&& scene)
{
	m_currentScene = std::move(scene);
}

void SceneManager::draw()
{
	m_currentScene->draw();
}

void SceneManager::update()
{
	m_currentScene->update();
	if (m_currentScene->shouldChange())
	{
		std::unique_ptr<Scene> tmp(m_currentScene->getNextScene());
		delete m_currentScene.release();
		m_currentScene = std::move(tmp);
	}
}

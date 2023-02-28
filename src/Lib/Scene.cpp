#include "Scene.h"

void Scene::update()
{

}

void Scene::draw()
{

}

bool Scene::shouldChange() const
{
	return m_shouldChange;
}

Scene* Scene::getNextScene()
{
	return m_nextScene;
}

void Scene::changeScene(Scene* nextScene)
{
	m_nextScene = nextScene;
	m_shouldChange = 1;
}

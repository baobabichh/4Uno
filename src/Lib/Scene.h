#pragma once
#include <SFML/Graphics.hpp>


class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	virtual void update();
	virtual void draw();
	bool shouldChange()const;
	Scene* getNextScene();

protected:
	void changeScene(Scene* nextScene);

private:
	Scene* m_nextScene = nullptr;
	bool m_shouldChange = 0;
};
#include "SceneManager.h"

SceneManager::SceneManager(sf::Window* win)
{
	window = win;
	camera->setCenter(0, 0);
}

void SceneManager::SetCamera(float x, float y)
{
	camera->setCenter(x, y);
}

void SceneManager::LoadLevel(std::string levelName)
{
	
}

void SceneManager::UnloadLevel()
{

}

void SceneManager::Dophysics()
{
	
}

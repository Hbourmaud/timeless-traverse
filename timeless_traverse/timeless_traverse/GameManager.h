#pragma once
#include "SFML/Graphics.hpp"
#include "../timeless_traverse/Managers/SceneManager.h"
#include "Entities/Entity.h"


class GameManager 
{
public:
	static GameManager& GetInstance()
	{
		static GameManager instance;
		return instance;
	}
	void Init();

private:
	GameManager();
	~GameManager();

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
	
	void GameLoop();
	int screenWidth;
	int screenHeight;
	float dt;
	sf::Clock startClock;
};

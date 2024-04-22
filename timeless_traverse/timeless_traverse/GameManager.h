#pragma once
#include "SFML/Graphics.hpp"


class GameManager 
{
public:
	GameManager();
	~GameManager();

	void Init();

	//void
private:
	void GameLoop();
	int screenWidth;
	int screenHeight;
	float dt;
	sf::Clock startClock;
};
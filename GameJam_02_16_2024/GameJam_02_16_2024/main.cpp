// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : main.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include <raylib.h>
#include <iostream>
#include "GlobalValues.h"
#include "Timer.h"
#include "GameStateManager.h"
#include "Player.h"
#include "RhythmSystem.h"
#include <SFML/Audio.hpp> 

Timer* timer;
GameStateManager* gameStateManager;

int main()
{

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);
	
	timer = new Timer();
	gameStateManager = new GameStateManager();

	timer->Init();
	gameStateManager->Init();

	// Temporary codes
	gameStateManager->SetStateEnum(GameStateEnum::MainMenu);

	while (WindowShouldClose() == false)
	{
		float frameTime = GetFrameTime();

		BeginDrawing();
		ClearBackground(Color{ 20, 160, 133, 255 });

		// Timer
		timer->Update(frameTime);

		// GameStateManager
		gameStateManager->Update(frameTime);
		gameStateManager->Draw();

		EndDrawing();
	}

	gameStateManager->Clear();

	delete gameStateManager;
	delete timer;

	return 0;
}
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

Timer* timer;
GameStateManager* gameStateManager;
Player* player;
RhythmSystem* rhythmSystem;

int main()
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);
	
	timer = new Timer();
	gameStateManager = new GameStateManager();
	player = new Player();
	rhythmSystem = new RhythmSystem();

	timer->Init();
	gameStateManager->Init();
	rhythmSystem->Init();

	// Temporary codes
	gameStateManager->SetStateEnum(GameStateEnum::MainMenu);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		
		// Draw Something
		ClearBackground(Color{ 20, 160, 133, 255 });
		
		// Timer
		timer->Update(GetFrameTime());

		// GameStateManager
		gameStateManager->Update(GetFrameTime());
		gameStateManager->Draw();

		EndDrawing();
	}

	gameStateManager->Clear();

	delete rhythmSystem;
	delete player;
	delete gameStateManager;
	delete timer;

	return 0;
}
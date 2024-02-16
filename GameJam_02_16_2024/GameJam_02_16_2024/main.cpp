// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : main.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include <raylib.h>
#include <iostream>
#include "Timer.h"
#include "RhythmSystem.h"

#define GAME_NAME "Smile, Programmer!"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

Timer* timer;
RhythmSystem* rhythmSystem;

int main()
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);

	timer = new Timer();
	rhythmSystem = new RhythmSystem();

	timer->Init();
	rhythmSystem->Init();

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		
		// Draw Something
		ClearBackground(Color{ 20, 160, 133, 255 });
		
		// Timer
		timer->Update(GetFrameTime());

		// RhythmSystem
		rhythmSystem->Update(GetFrameTime());

		EndDrawing();
	}

	delete rhythmSystem;
	delete timer;

	return 0;
}
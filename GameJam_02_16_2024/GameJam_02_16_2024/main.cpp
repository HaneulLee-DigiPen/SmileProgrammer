// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include <raylib.h>
#include <iostream>
#include "Timer.h"

#define GAME_NAME "Smile, Programmer!"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

Timer timer;

int main()
{

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		
		// Draw Something
		ClearBackground(Color{ 20, 160, 133, 255 });

		// Timer test block
		{
			timer.PrintOutTimeFromGameStart();
			timer.Update(GetFrameTime());
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
			{
				timer.ResetTimeFromGameStart();
			}
		}

		EndDrawing();
	}

	return 0;
}
// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : EndingState.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "GlobalValues.h"
#include "EndingState.h"

void EndingState::Init()
{
	std::cout << "Initializing EndingState..." << std::endl;

	Image endingImage = LoadImage("Assets/full_smile_front.png");
	m_endingTexture = LoadTextureFromImage(endingImage);
	UnloadImage(endingImage);
}

void EndingState::Update(float dt)
{
	if (IsMouseButtonPressed(MouseButton::MOUSE_BUTTON_LEFT) == true ||
		IsKeyPressed(KeyboardKey::KEY_BACKSPACE) == true)
	{
		gameStateManager->SetStateEnum(GameStateEnum::Game); // Need to be fixed
	}
}

void EndingState::Draw()
{
	DrawTexture(m_endingTexture, 0, 0, WHITE);
	DrawText("You finally finished your works! Congratulations!", 25, 25, 30, WHITE);
	DrawText("There will be more works to do next time...", 250, 60, 15, WHITE);
	DrawText("Press \"Space bar\" or Click \"Mouse left button\"!", 25, WINDOW_HEIGHT - 40, 30, WHITE);
}

void EndingState::Clear()
{

}
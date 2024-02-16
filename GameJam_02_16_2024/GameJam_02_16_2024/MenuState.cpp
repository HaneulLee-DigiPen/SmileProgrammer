#include "MenuState.h"
#include "GameStateManager.h"
#include <iostream>


void MenuState::Init()
{
	std::cout << "Initializing GameState..." << std::endl;;

	Image backgroundImage = LoadImage("Assets/mainMenuBackground.png");
	m_backgroundTexture = LoadTextureFromImage(backgroundImage);
	UnloadImage(backgroundImage);
}

void MenuState::Update(float dt)
{
	if (IsKeyPressed(KEY_ENTER) == true)
	{
		gameStateManager->SetStateEnum(GameStateEnum::Game);
	}
	else if(IsKeyPressed(KEY_ESCAPE) == true)
	{
		CloseWindow();
	}
}

void MenuState::Draw()
{
	DrawBackground();
	DrawTitle();
	DrawExplanation();
}

void MenuState::Clear()
{
	UnloadTexture(m_backgroundTexture);
}

void MenuState::DrawBackground()
{
	DrawTexture(m_backgroundTexture, 400 - m_backgroundTexture.width / 2, 300 - m_backgroundTexture.height / 2, WHITE);
}

void MenuState::DrawTitle()
{
	DrawRectangle(30, 90, 740, 100, ColorAlpha(GRAY, 0.4f));
	DrawText("Smile, Programer!", 50, 100, 80, BLACK);
}

void MenuState::DrawExplanation()
{
	DrawCircle(140, 540, 60, ColorAlpha(GRAY, 0.2f));
	DrawText("START", 80, 510, 35, GRAY);
	DrawText("ENTER", 90, 550, 30, BLACK);
	
	DrawCircle(665, 540, 60, ColorAlpha(GRAY, 0.2f));
	DrawText("EXIT", 615, 510, 40, GRAY);
	DrawText("ESC", 635, 550, 30, BLACK);

}
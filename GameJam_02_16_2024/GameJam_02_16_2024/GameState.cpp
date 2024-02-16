#include "GameState.h"
#include "Player.h"
#include <iostream>
#include <string>

void GameState::Init()
{
	Image backgroundImage = LoadImage("Assets/mainroom.png");
	backgroundtexture = LoadTextureFromImage(backgroundImage);
	UnloadImage(backgroundImage);
}

void GameState::Update(float dt)
{
	PlayerUpdate();
	GenerateTrash();
	DestroyTrash();
}

void GameState::Draw()
{
	DrawBackground();
	DrawPlayerStatus();
	DrawTrash();
}

void GameState::Clear()
{
	UnloadTexture(backgroundtexture);
}


void GameState::PlayerUpdate()
{
	if (checkDecreaseStatus == 2)
	{
		if ((int)timer->GetTimeFromGameStart() % playerStatusTime == 0)
		{
			checkDecreaseStatus = 1;
		}
	}

	if ((int)timer->GetTimeFromGameStart() % playerStatusTime != 0)
	{
		checkDecreaseStatus = 2;
	}

	if (checkDecreaseStatus == 1)
	{
		player->ChangeBathroom(-2);
		player->ChangeHungry(-3);
		player->ChangeSleep(-1);
		player->ChangeThirsty(-4);
		checkDecreaseStatus = 0;
	}


}

void GameState::DrawPlayerStatus()
{
	DrawText(TextFormat("Hyngrer  : %d", player->GetHungry()), 10, 505, 15, BLACK);
	DrawText(TextFormat("Thirsty  : %d", player->GetThirsty()), 10, 525, 15, BLACK);
	DrawText(TextFormat("Sleep    : %d", player->GetSleep()), 10, 545, 15, BLACK);
	DrawText(TextFormat("Bathroom : %d", player->GetBathroom()), 10, 565, 15, BLACK);
	
	if (player->GetHungry() > 30)
	{
		DrawRectangle(110, 505, player->GetHungry(), 15, GREEN);
	}
	else
	{
		DrawRectangle(110, 505, player->GetHungry(), 15, RED);
	}

	if (player->GetThirsty() > 30)
	{
		DrawRectangle(110, 525, player->GetThirsty(), 15, GREEN);
	}
	else
	{
		DrawRectangle(110, 525, player->GetThirsty(), 15, RED);
	}

	if (player->GetSleep() > 30)
	{
		DrawRectangle(110, 545, player->GetSleep(), 15, GREEN);
	}
	else
	{
		DrawRectangle(110, 545, player->GetSleep(), 15, RED);
	}
	if (player->GetBathroom() > 30)
	{
		DrawRectangle(110, 565, player->GetBathroom(), 15, GREEN);
	}
	else
	{
		DrawRectangle(110, 565, player->GetBathroom(), 15, RED);
	}

	DrawRectangleLines(109, 504, 100, 15, BLACK);
	DrawRectangleLines(109, 524, 100, 15, BLACK);
	DrawRectangleLines(109, 544, 100, 15, BLACK);
	DrawRectangleLines(109, 564, 100, 15, BLACK);
}

void GameState::DrawBackground()
{
	DrawTexture(backgroundtexture, 400 - backgroundtexture.width / 2, 300 - backgroundtexture.height / 2, WHITE);
}

void GameState::GenerateTrash()
{
	if (checkGenTrash == 2)
	{
		if ((int)timer->GetTimeFromGameStart() % genTrashTime == 0)
		{
			checkGenTrash = 1;
		}
	}

	if ((int)timer->GetTimeFromGameStart() % genTrashTime != 0)
	{
		checkGenTrash = 2;
	}

	if (checkGenTrash == 1)
	{
		trashVec.push_back(Trash{ GetRandomValue(140, 680), GetRandomValue(125, 500) });
		genTrashTime = GetRandomValue(3, 10);

		checkGenTrash = 0;
	}
}

void GameState::DrawTrash()
{
	for (int i = 0; i < trashVec.size(); ++i)
	{
		trashVec[i].Draw();
	}
}

void GameState::DestroyTrash()
{
	int trashW = 25;
	for (int i = trashVec.size() - 1; i >= 0; --i)
	{
		if (trashVec[i].GetPosX() - trashW >= GetMousePosition().x && trashVec[i].GetPosX() + trashW <= GetMousePosition().x &&
			trashVec[i].GetPosY() - trashW >= GetMousePosition().y && trashVec[i].GetPosY() + trashW <= GetMousePosition().y)
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
			{
				trashVec.erase(trashVec.begin() + i);
				break;
			}
		}
	}
}
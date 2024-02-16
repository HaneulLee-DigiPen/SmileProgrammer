// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : GameState.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "GameState.h"
#include "Player.h"
#include <iostream>
#include <string>

Player* player;

void GameState::Init()
{
	std::cout << "Initializing GameState..." << std::endl;;

	Image backgroundImage = LoadImage("Assets/mainroom.png");
	m_backgroundTexture = LoadTextureFromImage(backgroundImage);
	UnloadImage(backgroundImage);

	player = new Player();
}

void GameState::Update(float dt)
{
	PlayerUpdate(dt);
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
	UnloadTexture(m_backgroundTexture);

	delete player;
}

void GameState::AddMoney(unsigned int money)
{
	m_money += money;
}

void GameState::SpendMoney(unsigned int money)
{
	m_money -= money;
}

void GameState::SetMoney(unsigned int money)
{
	m_money = money;
}

unsigned int GameState::GetMoney() const
{
	return m_money;
}

void GameState::PlayerUpdate(float dt)
{
	player->Update(dt);

	if (m_checkDecreaseStatus == 2)
	{
		if ((int)timer->GetTimeFromGameStart() % m_playerStatusTime == 0)
		{
			m_checkDecreaseStatus = 1;
		}
	}

	if ((int)timer->GetTimeFromGameStart() % m_playerStatusTime != 0)
	{
		m_checkDecreaseStatus = 2;
	}

	if (m_checkDecreaseStatus == 1)
	{
		player->ChangeBathroom(-2);
		player->ChangeHungry(-3);
		player->ChangeSleep(-1);
		player->ChangeThirsty(-4);
		m_checkDecreaseStatus = 0;
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
	DrawTexture(m_backgroundTexture, 400 - m_backgroundTexture.width / 2, 300 - m_backgroundTexture.height / 2, WHITE);
}

void GameState::GenerateTrash()
{
	if (m_checkGenTrash == 2)
	{
		if ((int)timer->GetTimeFromGameStart() % m_genTrashTime == 0)
		{
			m_checkGenTrash = 1;
		}
	}

	if ((int)timer->GetTimeFromGameStart() % m_genTrashTime != 0)
	{
		m_checkGenTrash = 2;
	}

	if (m_checkGenTrash == 1)
	{
		m_trashVec.push_back(Trash{ GetRandomValue(140, 680), GetRandomValue(125, 500) });
		m_genTrashTime = GetRandomValue(3, 10);

		m_checkGenTrash = 0;
	}
}

void GameState::DrawTrash()
{
	for (int i = 0; i < m_trashVec.size(); ++i)
	{
		m_trashVec[i].Draw();
	}
}

void GameState::DestroyTrash()
{
	int trashW = 25;
	for (int i = static_cast<int>(m_trashVec.size()) - 1; i >= 0; --i)
	{
		if (m_trashVec[i].GetPosX() - trashW >= GetMousePosition().x && m_trashVec[i].GetPosX() + trashW <= GetMousePosition().x &&
			m_trashVec[i].GetPosY() - trashW >= GetMousePosition().y && m_trashVec[i].GetPosY() + trashW <= GetMousePosition().y)
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
			{
				m_trashVec.erase(m_trashVec.begin() + i);
				break;
			}
		}
	}
}
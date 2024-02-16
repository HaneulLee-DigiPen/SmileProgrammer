// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : GameState.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "GameState.h"
#include "Player.h"
#include <iostream>
#include <string>

void GameState::Init()
{
	std::cout << "Initializing GameState..." << std::endl;;

	Image backgroundImage = LoadImage("Assets/mainroom.png");
	m_backgroundTexture = LoadTextureFromImage(backgroundImage);
	UnloadImage(backgroundImage);

	Image smartphoneImage = LoadImage("Assets/smartphone.png");
	m_smartphoneUITexture = LoadTextureFromImage(smartphoneImage);
	UnloadImage(smartphoneImage);

	Image smartphoneIconImage = LoadImage("Assets/smartphoneIcon.png");
	ImageResize(&smartphoneIconImage, 450, 500);
	m_smartphoneIconTexture = LoadTextureFromImage(smartphoneIconImage);
	UnloadImage(smartphoneIconImage);

	Image smartphoneFrameImage = LoadImage("Assets/smartphoneFrame.png");
	ImageResize(&smartphoneFrameImage, 450, 500);
	m_smartphoneFrameTexture = LoadTextureFromImage(smartphoneFrameImage);
	UnloadImage(smartphoneFrameImage);

	Image m_orderFoodImage = LoadImage("Assets/smartphone.png");
	m_orderFoodTexture = LoadTextureFromImage(m_orderFoodImage);
	UnloadImage(m_orderFoodImage);
}

void GameState::Update(float dt)
{
	PlayerUpdate();
	GenerateTrash();
	DestroyTrash();
	UpdateSmartPhone();
}

void GameState::Draw()
{
	DrawBackground();
	DrawPlayerStatus();
	DrawTrash();
	DrawSmartPhoneUI();
	DrawSmartPhoneIcon();
}

void GameState::Clear()
{
	UnloadTexture(m_backgroundTexture);
	UnloadTexture(m_smartphoneUITexture);
	UnloadTexture(m_smartphoneIconTexture);
	UnloadTexture(m_smartphoneFrameTexture);
}


void GameState::PlayerUpdate()
{
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
	DrawText(TextFormat("Thirsty   : %d", player->GetThirsty()), 10, 525, 15, BLACK);
	DrawText(TextFormat("Sleep      : %d", player->GetSleep()), 10, 545, 15, BLACK);
	DrawText(TextFormat("Bathroom : %d", player->GetBathroom()), 10, 565, 15, BLACK);
	
	if (player->GetHungry() > 30)
	{
		DrawRectangle(115, 505, player->GetHungry(), 15, GREEN);
	}
	else
	{
		DrawRectangle(115, 505, player->GetHungry(), 15, RED);
	}

	if (player->GetThirsty() > 30)
	{
		DrawRectangle(115, 525, player->GetThirsty(), 15, GREEN);
	}
	else
	{
		DrawRectangle(115, 525, player->GetThirsty(), 15, RED);
	}

if (player->GetSleep() > 30)
{
	DrawRectangle(115, 545, player->GetSleep(), 15, GREEN);
}
else
{
	DrawRectangle(115, 545, player->GetSleep(), 15, RED);
}
if (player->GetBathroom() > 30)
{
	DrawRectangle(115, 565, player->GetBathroom(), 15, GREEN);
}
else
{
	DrawRectangle(115, 565, player->GetBathroom(), 15, RED);
}

DrawRectangleLines(115, 505, 100, 15, BLACK);
DrawRectangleLines(115, 525, 100, 15, BLACK);
DrawRectangleLines(115, 545, 100, 15, BLACK);
DrawRectangleLines(115, 565, 100, 15, BLACK);
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
		int generateMinTime = 7;
		int generateMaxTime = 12;

		int generatePosXMin = 140;
		int generatePosXMax = 660;

		int generatePosYMin = 125;
		int generatePosYMax = 480;

		Trash trash{ GetRandomValue(generatePosXMin, generatePosXMax), GetRandomValue(generatePosYMin, generatePosYMax) };
		trash.Init();
		trashVec.push_back(trash);
		m_genTrashTime = GetRandomValue(generateMinTime, generateMaxTime);

		m_checkGenTrash = 0;
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
	int trashW = 50;
	for (int i = (int)(trashVec.size()) - 1; i >= 0; --i)
	{
		if (trashVec[i].GetPosX() <= (int)(GetMousePosition().x) && trashVec[i].GetPosX() + trashW >= (int)(GetMousePosition().x) &&
			trashVec[i].GetPosY() <= (int)(GetMousePosition().y) && trashVec[i].GetPosY() + trashW >= (int)(GetMousePosition().y))
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
			{
				trashVec[i].Clear();
				trashVec.erase(trashVec.begin() + i);
				break;
			}
		}
	}
}

void GameState::DrawSmartPhoneUI()
{
	DrawTexture(m_smartphoneUITexture, m_smartphoneUI_posX, m_smartphoneUI_posY, WHITE);
}

void GameState::UpdateSmartPhone()
{
	if (m_checkClickSmartPhone == false)
	{
		if ((int)(GetMousePosition().x) >= m_smartphoneUI_posX && (int)(GetMousePosition().x) <= m_smartphoneUI_posX + m_smartphoneUITexture.width &&
			(int)(GetMousePosition().y) >= m_smartphoneUI_posY && (int)(GetMousePosition().y) <= m_smartphoneUI_posX + m_smartphoneUITexture.height)
		{
			DrawRectangleLines(m_smartphoneUI_posX, m_smartphoneUI_posY, m_smartphoneUITexture.width, m_smartphoneUITexture.height, RED);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
			{
				m_checkClickSmartPhone = true;
				m_smartPhoneWhichIcon = 0;
				m_smartPhonePage = 0;
			}
		}
	}
	else
	{
		if (IsKeyPressed(KEY_RIGHT) == true)
		{
			if (m_smartPhoneWhichIcon == 2)
			{
				m_smartPhoneWhichIcon = 0;
			}
			else
			{
				m_smartPhoneWhichIcon += 1;
			}
		}
		else if(IsKeyPressed(KEY_LEFT) == true)
		{
			if (m_smartPhoneWhichIcon == 0)
			{
				m_smartPhoneWhichIcon = 2;
			}
			else
			{
				m_smartPhoneWhichIcon -= 1;
			}
		}
		
		if (m_smartPhonePage == 0)
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				m_smartPhonePage = m_smartPhoneWhichIcon + 1;
			}
			else if (IsKeyPressed(KEY_RIGHT_SHIFT) == true)
			{
				m_checkClickSmartPhone = false;
			}
		}
		else
		{
			if (IsKeyPressed(KEY_RIGHT_SHIFT) == true)
			{
				m_smartPhonePage = 0;
			}
		}
	}
}

void GameState::DrawSmartPhoneIcon()
{
	if (m_checkClickSmartPhone == true)
	{
		DrawRectangle(0, 0, 800, 600, ColorAlpha(WHITE, 0.8));
		DrawSmartPhoneExplanation();

		if (m_smartPhonePage == 0)
		{
			m_pageWhichOne = 0;
			DrawTexture(m_smartphoneIconTexture, m_smartphoneIcon_posX, m_smartphoneIcon_posY, WHITE);

			if (m_smartPhoneWhichIcon == 0)
			{
				DrawCircleLines(341, 270, 40, BLACK);
				DrawCircleLines(341, 270, 41, BLACK);
				DrawCircleLines(341, 270, 42, BLACK);
				DrawCircleLines(341, 270, 43, BLACK);
				DrawCircleLines(341, 270, 44, BLACK);

				DrawText("You can order", 600, 230, 20, BLACK);
				DrawText("Food", 630, 260, 30, BLACK);

			}
			else if (m_smartPhoneWhichIcon == 1)
			{
				DrawCircleLines(419, 270, 40, BLACK);
				DrawCircleLines(419, 270, 41, BLACK);
				DrawCircleLines(419, 270, 42, BLACK);
				DrawCircleLines(419, 270, 43, BLACK);
				DrawCircleLines(419, 270, 44, BLACK);

				DrawText("You can order", 600, 230, 20, BLACK);
				DrawText("Drink", 630, 260, 30, BLACK);
			}
			else
			{
				DrawCircleLines(497, 270, 40, BLACK);
				DrawCircleLines(497, 270, 41, BLACK);
				DrawCircleLines(497, 270, 42, BLACK);
				DrawCircleLines(497, 270, 43, BLACK);
				DrawCircleLines(497, 270, 44, BLACK);

				DrawText("You can upgrade", 595, 230, 20, BLACK);
				DrawText("Furniture", 605, 260, 30, BLACK);
			}
		}
		else if (m_smartPhonePage == 1)
		{
			DrawSmartPhonePage_1();
		}
		else if (m_smartPhonePage == 2)
		{
			DrawSmartPhonePage_2();
		}
		else if (m_smartPhonePage == 3)
		{
			DrawSmartPhonePage_3();
		}

	}
}

void GameState::DrawSmartPhoneExplanation()
{
	DrawText("Move : Arraw Key", 40, 200, 20, BLACK);
	DrawText("Choose : Enter Key", 40, 250, 20, BLACK);
	DrawText("Go Back : ESC Key", 40, 300, 20, BLACK);
}

void GameState::DrawSmartPhonePage_1()
{
	int onigiriP = 10;
	int onigiriM = 20;

	int hamburgerP = 20;
	int hamburgerM = 35;

	int pizzaP = 30;
	int pizzaM = 50;

	DrawTexture(m_smartphoneFrameTexture, m_smartphoneIcon_posX, m_smartphoneIcon_posY, WHITE);
	DrawCircle(360, 140, 30, SKYBLUE);
	DrawText("Food", 400, 125, 30, BLACK);

	if (IsKeyPressed(KEY_DOWN) == true)
	{
		if (m_pageWhichOne == 2)
		{
			m_pageWhichOne = 0;
		}
		else
		{
			m_pageWhichOne += 1;
		}
	}
	else if (IsKeyPressed(KEY_UP) == true)
	{
		if (m_pageWhichOne == 0)
		{
			m_pageWhichOne = 2;
		}
		else
		{
			m_pageWhichOne -= 1;
		}
	}

	DrawRectangle(m_option_X, optionHeight[m_pageWhichOne], m_option_W, m_option_H, ColorAlpha(GRAY, 0.4));

	DrawRectangleLines(m_option_X, optionHeight[0], m_option_W, m_option_H, BLACK);
	DrawRectangleLines(m_option_X, optionHeight[1], m_option_W, m_option_H, BLACK);
	DrawRectangleLines(m_option_X, optionHeight[2], m_option_W, m_option_H, BLACK);

	DrawText("Onigiri", m_option_X + 15, optionHeight[0]+10, 25, BLACK);
	DrawText(TextFormat("$ %d", onigiriM), m_option_X + 180, optionHeight[0] + 10, 25, BLACK);

	DrawText("Hamburger", m_option_X + 15, optionHeight[1] + 10, 25, BLACK);
	DrawText(TextFormat("$ %d", hamburgerM), m_option_X + 180, optionHeight[1] + 10, 25, BLACK);

	DrawText("Pizza", m_option_X + 15, optionHeight[2] + 10, 25, BLACK);
	DrawText(TextFormat("$ %d", pizzaM), m_option_X + 180, optionHeight[2] + 10, 25, BLACK);
	

	if (m_pageWhichOne == 0)
	{
		DrawText(TextFormat("Hunger -%d", onigiriP), 600, 230, 30, BLACK);
		if (IsKeyPressed(KEY_ENTER) == true)
		{
			//만약 돈이 20만큼 있다면
			if (m_canOrder == true)
			{
				m_isFirst = true;
				OrderFood(onigiriP);
			}
			else
			{
				DrawText("You should wait previous delivery.", 600, 230, 30, BLACK);
			}
		}
	}
	else if (m_pageWhichOne == 1)
	{
		DrawText(TextFormat("Hunger -%d", hamburgerP), 600, 230, 30, BLACK);
		if (IsKeyPressed(KEY_ENTER) == true)
		{
			//만약 돈이 35만큼 있다면
			if (m_canOrder == true)
			{
				m_isFirst = true;
				OrderFood(hamburgerP);
			}
			else
			{
				DrawText("You should wait previous delivery.", 600, 230, 30, BLACK);
			}
		}
	}
	else if (m_pageWhichOne == 2)
	{
		DrawText(TextFormat("Hunger -%d", pizzaP), 600, 230, 30, BLACK);
		if (IsKeyPressed(KEY_ENTER) == true)
		{
			//만약 돈이 50만큼 있다면
			if (m_canOrder == true)
			{
				m_isFirst = true;
				OrderFood(pizzaP);
			}
			else
			{
				DrawText("You should wait previous delivery.", 600, 230, 30, BLACK);
			}
		}
	}

}

void GameState::DrawSmartPhonePage_2()
{
	DrawTexture(m_smartphoneFrameTexture, m_smartphoneIcon_posX, m_smartphoneIcon_posY, WHITE);
	DrawCircle(360, 140, 30, RED);
	DrawText("Drink", 400, 125, 30, BLACK);
}

void GameState::DrawSmartPhonePage_3()
{
	DrawTexture(m_smartphoneFrameTexture, m_smartphoneIcon_posX, m_smartphoneIcon_posY, WHITE);
	DrawCircle(330, 140, 30, BLUE);
	DrawText("Furniture", 370, 125, 30, BLACK);
}

void GameState::OrderFood(int point)
{
	if (m_isFirst == true)
	{
		m_isFirst = false;
		m_firstTime = timer->GetTimeFromGameStart();
		m_orderTime = GetRandomValue(5, 8);
	}
	if (m_firstTime + m_orderTime <= timer->GetTimeFromGameStart())
	{
		m_isOrderArrive = true;
	}
	if (m_isOrderArrive == true)
	{
		
	}
}

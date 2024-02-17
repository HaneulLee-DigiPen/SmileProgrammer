// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : GameState.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "GameState.h"
#include "Player.h"
#include "GameStateManager.h"
#include <iostream>
#include <string>

Player* player;

void GameState::Init()
{
	std::cout << "Initializing GameState..." << std::endl;;

	player = new Player();

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

	Image m_orderFoodImage = LoadImage("Assets/orderFood.png");
	m_orderFoodTexture = LoadTextureFromImage(m_orderFoodImage);
	UnloadImage(m_orderFoodImage);

	Image m_orderDrinkImage = LoadImage("Assets/orderDrink.png");
	m_orderDrinkTexture = LoadTextureFromImage(m_orderDrinkImage);
	UnloadImage(m_orderDrinkImage);

	Image m_singleMonitorImage = LoadImage("Assets/singlemonitor.png");
	m_singleMonitorTexture = LoadTextureFromImage(m_singleMonitorImage);
	UnloadImage(m_singleMonitorImage);

	Image m_doubleMonitorImage = LoadImage("Assets/doublemonitor.png");
	m_doubleMonitorTexture = LoadTextureFromImage(m_doubleMonitorImage);
	UnloadImage(m_doubleMonitorImage);

	Image m_tripleMonitorImage = LoadImage("Assets/triplemonitor.png");
	m_tripleMonitorTexture = LoadTextureFromImage(m_tripleMonitorImage);
	UnloadImage(m_tripleMonitorImage);

	Image m_quadMonitorImage = LoadImage("Assets/quadramonitor.png");
	m_quadMonitorTexture = LoadTextureFromImage(m_quadMonitorImage);
	UnloadImage(m_quadMonitorImage);

	Image m_sleepingBagImage = LoadImage("Assets/sleepingBag.png");
	m_sleepingBagTexture = LoadTextureFromImage(m_sleepingBagImage);
	UnloadImage(m_sleepingBagImage);

	Image m_bedImage = LoadImage("Assets/bed.png");
	m_bedTexture = LoadTextureFromImage(m_bedImage);
	UnloadImage(m_bedImage);

	Image m_airConditionerImage = LoadImage("Assets/aircon.png");
	m_airConditionerTexture = LoadTextureFromImage(m_airConditionerImage);
	UnloadImage(m_airConditionerImage);

	Image m_fanImage = LoadImage("Assets/fan.png");
	m_fanTexture = LoadTextureFromImage(m_fanImage);
	UnloadImage(m_fanImage);

	Image m_curtainImage = LoadImage("Assets/contrain.png");
	m_curtainTexture = LoadTextureFromImage(m_curtainImage);
	UnloadImage(m_curtainImage);

	Image m_shelfImage = LoadImage("Assets/book.png");
	m_shelfTexture = LoadTextureFromImage(m_shelfImage);
	UnloadImage(m_shelfImage);

	Image m_refrigeratorImage = LoadImage("Assets/refrigester.png");
	m_refrigeratorTexture = LoadTextureFromImage(m_refrigeratorImage);
	UnloadImage(m_refrigeratorImage);
}

void GameState::Update(float dt)
{
	PlayerUpdate(dt);
	GenerateTrash();
	DestroyTrash();
	UpdateSmartPhone();
	if (IsKeyPressed(KeyboardKey::KEY_ENTER) && m_checkClickSmartPhone == false)
	{
		if (player->enoughPoints() == true)
		{
			if (monitorState->GetCurrentLevel() < 3)
			{
				std::cout << monitorState->GetCurrentLevel() << std::endl;
				gameStateManager->SetStateEnum(GameStateEnum::Monitor);
			}
			else if (monitorState->GetCurrentLevel() < 6 && m_dualMonitor == true)
			{
				gameStateManager->SetStateEnum(GameStateEnum::Monitor);
			}
			else if (monitorState->GetCurrentLevel() < 9 && m_tripleMonitor == true)
			{
				gameStateManager->SetStateEnum(GameStateEnum::Monitor);
			}
			else if (monitorState->GetCurrentLevel() < 12 && m_quadMonitor == true)
			{
				gameStateManager->SetStateEnum(GameStateEnum::Monitor);
			}
		}
	}
	GetFood();
	PlayerSleep();
	PlayerToilet();
}

void GameState::Draw()
{
	DrawBackground();
	DrawBackgroundExplanation();
	DrawBed();
	DrawCurtain();
	DrawShelf();
	DrawFan();
	DrawAirConditioner();
	DrawRefrigerator();
	DrawMonitor();
	DrawPlayerStatus();
	DrawTextClick();
	DrawTrash();
	DrawSmartPhoneUI();
	DrawSmartPhoneIcon();


	if (monitorState->GetCurrentLevel() < 3) {}
	else if (monitorState->GetCurrentLevel() < 6 && m_dualMonitor == true) {}
	else if (monitorState->GetCurrentLevel() < 9 && m_tripleMonitor == true) {}
	else if (monitorState->GetCurrentLevel() < 12 && m_quadMonitor == true) {}
	else 
	{
		DrawText("You need to upgrade your monitor.", 180, 200, 30,BLACK);
	}
	DrawArriveFood();
	DrawMoneyUI();
	DrawWaitTime();
	Fadeout();
	
}

void GameState::Clear()
{
	UnloadTexture(m_backgroundTexture);

	delete player;
	UnloadTexture(m_smartphoneUITexture);
	UnloadTexture(m_smartphoneIconTexture);
	UnloadTexture(m_smartphoneFrameTexture);
	UnloadTexture(m_orderFoodTexture);
}

void GameState::DrawBackgroundExplanation()
{
	DrawText("Monitor", 731, 280, 17, GRAY);
	DrawText("Enter", 732, 300, 20, BLACK);
}

void GameState::DrawTextClick()
{
	//bed
	DrawText("Click!", 600, 450, 20, BLACK);

	//bathroom
	DrawText("Click!", 160, 220, 20, BLACK);
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

bool GameState::GetCurtain() const
{
	return m_curtain;
}

bool GameState::GetFan() const
{
	return m_fan;
}

bool GameState::GetShelf() const
{
	return m_shelf;
}

bool GameState::GetBed() const
{
	return m_bed;
}
bool GameState::GetRefrigerator() const
{
	return m_refrigerator;
}

bool GameState::GetAirConditioner() const
{
	return m_airConditioner;
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
		m_trashVec.push_back(trash);
		m_genTrashTime = GetRandomValue(generateMinTime, generateMaxTime);

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
	int trashW = 50;
	for (int i = (int)(m_trashVec.size()) - 1; i >= 0; --i)
	{
		if (m_trashVec[i].GetPosX() <= (int)(GetMousePosition().x) && m_trashVec[i].GetPosX() + trashW >= (int)(GetMousePosition().x) &&
			m_trashVec[i].GetPosY() <= (int)(GetMousePosition().y) && m_trashVec[i].GetPosY() + trashW >= (int)(GetMousePosition().y))
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
			{
				m_trashVec[i].Clear();
				m_trashVec.erase(m_trashVec.begin() + i);
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
			if (isPressed == false)
			{
				if (IsKeyPressed(KEY_ENTER) == true)
				{
					m_smartPhonePage = m_smartPhoneWhichIcon + 1;
					isPressed = true;
				}
			}
			if (IsKeyPressed(KEY_ENTER) == false)
			{
				isPressed = false;
			}
			if (IsKeyPressed(KEY_RIGHT_SHIFT) == true)
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
		DrawRectangle(0, 0, 800, 600, ColorAlpha(WHITE, 0.8f));
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
	int onigiriM = 10;

	int hamburgerP = 20;
	int hamburgerM = 20;

	int pizzaP = 30;
	int pizzaM = 30;

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
			std::cout << "Down Push" << std::endl;
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

	DrawRectangle(m_option_X, optionHeight[m_pageWhichOne], m_option_W, m_option_H, ColorAlpha(GRAY, 0.4f));

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
		if (isPressed == false)
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				if (GetMoney() >= onigiriM)
				{
					if (m_canOrder == true)
					{
						SpendMoney(onigiriM);
						m_isFirst = true;
						OrderFood();
						isFood = true;
						m_orderPoint = onigiriP;
					}
					else
					{
						DrawText("You should wait previous delivery.", 600, 230, 30, BLACK);
					}
				}
				isPressed = true;
			}
		}
		if (IsKeyPressed(KEY_ENTER) == false)
		{
			isPressed = false;
		}

		
	}
	else if (m_pageWhichOne == 1)
	{
		DrawText(TextFormat("Hunger -%d", hamburgerP), 600, 230, 30, BLACK);
		if (isPressed == false)
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				if (GetMoney() >= hamburgerM)
				{
					if (m_canOrder == true)
					{
						SpendMoney(hamburgerM);
						m_isFirst = true;
						OrderFood();
						isFood = true;
						m_orderPoint = hamburgerP;
					}
					else
					{
						DrawText("You should wait previous delivery.", 600, 230, 30, BLACK);
					}
				}
			}
		}
		if (IsKeyPressed(KEY_ENTER) == false)
		{
			isPressed = false;
		}
	}
	else if (m_pageWhichOne == 2)
	{
		DrawText(TextFormat("Hunger -%d", pizzaP), 600, 230, 30, BLACK);
		if (isPressed == false)
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				if (GetMoney() >= pizzaM)
				{
					if (m_canOrder == true)
					{
						SpendMoney(pizzaM);
						m_isFirst = true;
						OrderFood();
						isFood = true;
						m_orderPoint = pizzaP;
					}
					else
					{
						DrawText("You should wait previous delivery.", 600, 230, 30, BLACK);
					}
				}
				isPressed = true;
			}
		}
		if (IsKeyPressed(KEY_ENTER) == false)
		{
			isPressed = false;
		}
		
	}

}

void GameState::DrawSmartPhonePage_2()
{
	int waterP = 10;
	int waterM = 10;

	int coffeeP = 20;
	int coffeeM = 20;

	int energyDrinkP = 30;
	int energyDrinkM = 30;

	DrawTexture(m_smartphoneFrameTexture, m_smartphoneIcon_posX, m_smartphoneIcon_posY, WHITE);
	DrawCircle(360, 140, 30, RED);
	DrawText("Drink", 400, 125, 30, BLACK);

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

	DrawText("Water", m_option_X + 15, optionHeight[0] + 10, 25, BLACK);
	DrawText(TextFormat("$ %d", waterM), m_option_X + 180, optionHeight[0] + 10, 25, BLACK);

	DrawText("Coffee", m_option_X + 15, optionHeight[1] + 10, 25, BLACK);
	DrawText(TextFormat("$ %d", coffeeM), m_option_X + 180, optionHeight[1] + 10, 25, BLACK);

	DrawText("Energy Drink", m_option_X + 15, optionHeight[2] + 10, 25, BLACK);
	DrawText(TextFormat("$ %d", energyDrinkM), m_option_X + 180, optionHeight[2] + 10, 25, BLACK);


	if (m_pageWhichOne == 0)
	{
		DrawText(TextFormat("Thirsty -%d", waterP), 600, 230, 30, BLACK);
		if (isPressed == false)
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				if (GetMoney() >= waterM)
				{
					if (m_canOrder == true)
					{
						SpendMoney(waterM);
						m_isFirst = true;
						OrderFood();
						isFood = false;
						m_orderPoint = waterP;
					}
					else
					{
						DrawText("You should wait previous delivery.", 600, 230, 30, BLACK);
					}
				}
				isPressed = true;
			}
		}
		if (IsKeyPressed(KEY_ENTER) == false)
		{
			isPressed = false;
		}


	}
	else if (m_pageWhichOne == 1)
	{
		DrawText(TextFormat("Thirsty -%d", coffeeP), 600, 230, 30, BLACK);
		if (isPressed == false)
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				if (GetMoney() >= coffeeM)
				{
					if (m_canOrder == true)
					{
						SpendMoney(coffeeM);
						m_isFirst = true;
						isFood = false;
						OrderFood();
						m_orderPoint = coffeeP;
					}
					else
					{
						DrawText("You should wait previous delivery.", 600, 230, 30, BLACK);
					}
				}
			}
		}
		if (IsKeyPressed(KEY_ENTER) == false)
		{
			isPressed = false;
		}
	}
	else if (m_pageWhichOne == 2)
	{
		DrawText(TextFormat("Thirsty -%d", energyDrinkP), 600, 230, 30, BLACK);
		if (isPressed == false)
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				if (GetMoney() >= energyDrinkM)
				{
					if (m_canOrder == true)
					{
						SpendMoney(energyDrinkM);
						m_isFirst = true;
						OrderFood();
						isFood = false;
						m_orderPoint = energyDrinkP;
					}
					else
					{
						DrawText("You should wait previous delivery.", 600, 230, 30, BLACK);
					}
				}
				isPressed = true;
			}
		}
		if (IsKeyPressed(KEY_ENTER) == false)
		{
			isPressed = false;
		}

	}
}

void GameState::DrawSmartPhonePage_3()
{
	DrawTexture(m_smartphoneFrameTexture, m_smartphoneIcon_posX, m_smartphoneIcon_posY, WHITE);
	DrawCircle(330, 140, 30, BLUE);
	DrawText("Furniture", 370, 125, 30, BLACK);

	if (IsKeyPressed(KEY_DOWN) == true)
	{
		if (m_pageWhichOne == 6)
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
			m_pageWhichOne = 6;
		}
		else
		{
			m_pageWhichOne -= 1;
		}
	}

	DrawRectangle(m_option_X, optionHeight[m_pageWhichOne], m_option_W, m_option_H, ColorAlpha(GRAY, 0.4f));

	DrawRectangleLines(m_option_X, optionHeight[0], m_option_W, m_option_H, BLACK);
	DrawRectangleLines(m_option_X, optionHeight[1], m_option_W, m_option_H, BLACK);
	DrawRectangleLines(m_option_X, optionHeight[2], m_option_W, m_option_H, BLACK);
	DrawRectangleLines(m_option_X, optionHeight[3], m_option_W, m_option_H, BLACK);
	DrawRectangleLines(m_option_X, optionHeight[4], m_option_W, m_option_H, BLACK);
	DrawRectangleLines(m_option_X, optionHeight[5], m_option_W, m_option_H, BLACK);

	unsigned int doubleMonitorM = 400;
	unsigned int tripleMonitorM = 1200;
	unsigned int quadMonitorM = 3000;
	unsigned int curtainM = 100;
	unsigned int fanM = 150;
	unsigned int shelfM = 250;
	unsigned int bedM = 600;
	unsigned int refrigeratorM = 1200;
	unsigned int airConditionerM = 2400;

	if (monitorState->GetMonitorNumber() == MonitorNumber::One)
	{
		DrawText("Double monitor", m_option_X + 15, optionHeight[0] + 10, 25, BLACK);
		DrawText(TextFormat("$ %d", doubleMonitorM), m_option_X + 180, optionHeight[0] + 10, 25, BLACK);
	}
	else if (monitorState->GetMonitorNumber() == MonitorNumber::Two)
	{
		DrawText("Triple monitor", m_option_X + 15, optionHeight[0] + 10, 25, BLACK);
		DrawText(TextFormat("$ %d", tripleMonitorM), m_option_X + 180, optionHeight[0] + 10, 25, BLACK);
	}
	else if (monitorState->GetMonitorNumber() == MonitorNumber::Three)
	{
		DrawText("Quad monitor", m_option_X + 15, optionHeight[0] + 10, 25, BLACK);
		DrawText(TextFormat("$ %d", quadMonitorM), m_option_X + 180, optionHeight[0] + 10, 25, BLACK);
	}

	if (m_curtain == false)
	{
		DrawText("Curtain", m_option_X + 15, optionHeight[1] + 10, 25, BLACK);
		DrawText(TextFormat("$ %d", curtainM), m_option_X + 180, optionHeight[1] + 10, 25, BLACK);
	}

	if (m_fan == false)
	{
		DrawText("Fan", m_option_X + 15, optionHeight[2] + 10, 25, BLACK);
		DrawText(TextFormat("$ %d", fanM), m_option_X + 180, optionHeight[2] + 10, 25, BLACK);
	}

	if (m_shelf == false)
	{
		DrawText("Shelf", m_option_X + 15, optionHeight[3] + 10, 25, BLACK);
		DrawText(TextFormat("$ %d", shelfM), m_option_X + 180, optionHeight[3] + 10, 25, BLACK);
	}

	if (m_bed == false)
	{
		DrawText("Bed", m_option_X + 15, optionHeight[4] + 10, 25, BLACK);
		DrawText(TextFormat("$ %d", bedM), m_option_X + 180, optionHeight[4] + 10, 25, BLACK);
	}

	if (m_refrigerator == false)
	{
		DrawText("Refrigerator", m_option_X + 15, optionHeight[5] + 10, 25, BLACK);
		DrawText(TextFormat("$ %d", refrigeratorM), m_option_X + 180, optionHeight[5] + 10, 25, BLACK);
	}

	if (m_airConditioner == false)
	{
		DrawText("Air conditioner", m_option_X + 15, optionHeight[6] + 10, 25, BLACK);
		DrawText(TextFormat("$ %d", airConditionerM), m_option_X + 180, optionHeight[6] + 10, 25, BLACK);
	}

	if (m_checkClickSmartPhone == true)
	{
		if (m_pageWhichOne == 0)
		{
			DrawText("Unlock Level", 600, 230, 30, BLACK);
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				if (m_dualMonitor == false && m_money >= doubleMonitorM)
				{
					m_dualMonitor = true;
					m_money -= doubleMonitorM;
					monitorState->AddMonitor();
					player->DoubleIncomeMoney();
				}
				else if (m_tripleMonitor == false && m_money >= tripleMonitorM)
				{
					m_tripleMonitor = true;
					m_money -= tripleMonitorM;
					monitorState->AddMonitor();
					player->DoubleIncomeMoney();
				}
				else if (m_quadMonitor == false && m_money >= quadMonitorM)
				{
					m_quadMonitor = true;
					m_money -= quadMonitorM;
					monitorState->AddMonitor();
					player->DoubleIncomeMoney();
				}
			}
		}
		else if (m_pageWhichOne == 1)
		{
			DrawText("Fast income", 600, 230, 30, BLACK);
			DrawText("0.1 second", 600, 260, 30, BLACK);
			if (IsKeyPressed(KEY_ENTER) == true && m_money >= curtainM)
			{
				m_curtain = true;
				m_money -= curtainM;
			}
		}
		else if (m_pageWhichOne == 2)
		{
			DrawText("Fast income", 600, 230, 30, BLACK);
			DrawText("0.1 second", 600, 260, 30, BLACK);
			if (IsKeyPressed(KEY_ENTER) == true && m_money >= fanM)
			{
				m_fan = true;
				m_money -= fanM;
			}
		}
		else if (m_pageWhichOne == 3)
		{
			DrawText("Fast income", 600, 230, 30, BLACK);
			DrawText("0.1 second", 600, 260, 30, BLACK);
			if (IsKeyPressed(KEY_ENTER) == true && m_money >= shelfM)
			{
				m_shelf = true;
				m_money -= shelfM;
			}
		}
		else if (m_pageWhichOne == 4)
		{
			DrawText("Fast income", 600, 230, 30, BLACK);
			DrawText("0.2 second", 600, 260, 30, BLACK);
			if (IsKeyPressed(KEY_ENTER) == true && m_money >= bedM)
			{
				m_bed = true;
				m_money -= bedM;
			}
		}
		else if (m_pageWhichOne == 5)
		{
			DrawText("Fast income", 600, 230, 30, BLACK);
			DrawText("0.2 second", 600, 260, 30, BLACK);
			if (IsKeyPressed(KEY_ENTER) == true && m_money >= refrigeratorM)
			{
				m_refrigerator = true;
				m_money -= refrigeratorM;
			}
		}
		else if (m_pageWhichOne == 6)
		{
			DrawText("Fast income", 600, 230, 30, BLACK);
			DrawText("0.2 second", 600, 260, 30, BLACK);
			if (IsKeyPressed(KEY_ENTER) == true && m_money >= airConditionerM)
			{
				m_airConditioner = true;
				m_money -= airConditionerM;
			}
		}
	}
}

void GameState::OrderFood()
{
	m_checkClickSmartPhone = false;
	m_canOrder = false;
	m_smartPhoneWhichIcon = 0;
	m_smartPhonePage = 0;
	m_pageWhichOne = 0;

	if (m_isFirst == true)
	{
		m_isFirst = false;
		m_firstTime = timer->GetTimeFromGameStart();
		m_orderTime = GetRandomValue(2, 5);
		m_isOrderWait = true;
	}
}

void GameState::GetFood()
{
	if (m_isOrderArrive == true)
	{
		if (CheckCollisionPointCircle(GetMousePosition(), Vector2{ 180 , 462 }, 35) == true)
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
			{
				m_isGetFood = true;
				m_isOrderWait = false;
			}
		}
		if (m_isGetFood == true)
		{
			if (isFood == true)
			{
				player->ChangeHungry(m_orderPoint);
			}
			else
			{
				player->ChangeThirsty(m_orderPoint);
			}
			m_isGetFood = false;
			m_isOrderArrive = false;
			m_canOrder = true;
		}
	}
}

void GameState::DrawArriveFood()
{
	if (m_isOrderArrive == true)
	{
		DrawCircle(180, 462, 35, ColorAlpha(YELLOW, 0.3));

		if (isFood == true)
		{
			DrawTexture(m_orderFoodTexture, 150, 430, WHITE);
		}
		else
		{
			//음료 사진
			DrawTexture(m_orderDrinkTexture, 150, 430, WHITE);
		}
	}
}

void GameState::DrawMoneyUI()
{
	DrawText(TextFormat("Money : $ %d", GetMoney()), 650, 30, 20, BLACK);
}

void GameState::DrawBed()
{
	if (m_bed == true)
	{
		DrawTexture(m_bedTexture, 415, 320, WHITE);
	}
	else
	{
		DrawTexture(m_sleepingBagTexture, 445, 396, WHITE);
	}
}

void GameState::DrawMonitor()
{
	if (m_quadMonitor == true)
	{
		DrawTexture(m_quadMonitorTexture, 480, 210, WHITE);
	}
	else if (m_tripleMonitor == true)
	{
		DrawTexture(m_tripleMonitorTexture, 477, 225, WHITE);
	}
	else if (m_dualMonitor == true)
	{
		DrawTexture(m_doubleMonitorTexture, 475, 250, WHITE);
	}
	else
	{
		DrawTexture(m_singleMonitorTexture, 495, 265, WHITE);
	}
}

void GameState::DrawCurtain()
{
	if (m_curtain == true)
	{
		DrawTexture(m_curtainTexture, 470, 115, WHITE);
	}
}

void GameState::DrawShelf()
{
	if (m_shelf == true)
	{
		DrawTexture(m_shelfTexture, 280, 130, WHITE);
	}
}

void GameState::DrawRefrigerator()
{
	if (m_refrigerator == true)
	{
		DrawTexture(m_refrigeratorTexture, 230, 280, WHITE);
	}
}

void GameState::DrawFan()
{
	if (m_fan == true)
	{
		DrawTexture(m_fanTexture, 324, 55, WHITE);
	}
}

void GameState::DrawAirConditioner()
{
	if (m_airConditioner == true)
	{
		DrawTexture(m_airConditionerTexture, 200, 80, WHITE);
	}
}

void GameState::DrawWaitTime()
{
	if (m_isOrderWait == true)
	{
		if (m_firstTime + m_orderTime <= timer->GetTimeFromGameStart())
		{
			m_isOrderArrive = true;
		}
		else
		{
			DrawText(TextFormat("Wait..%d", (int)(m_firstTime + m_orderTime - (int)(timer->GetTimeFromGameStart()) + 1)), 180, 450, 15, BLACK);
		}
	}
}

void GameState::PlayerToilet()
{
	float mouseX = GetMousePosition().x;
	float mouseY = GetMousePosition().y;
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true &&
		mouseX > 155 && mouseX < 220 && mouseY > 215 && mouseY < 350)
	{
		player->ChangeBathroom(10);
		fadeoutFirst = true;
		isSleep = false;
		fadeTime = true;
	}
}

void GameState::PlayerSleep()
{
	float mouseX = GetMousePosition().x;
	float mouseY = GetMousePosition().y;
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true &&
		mouseX > 510 && mouseX < 680 && mouseY > 445 && mouseY < 500)
	{
		player->ChangeSleep(10);
		fadeoutFirst = true;
		isSleep = true;
		fadeTime = true;
	}
}

void GameState::Fadeout()
{
	if (fadeTime == true)
	{
		std::cout << "come" << std::endl;
		if (fadeoutFirst == true)
		{
			fadeoutFirst = false;
			firstFadeoutTime = timer->GetTimeFromGameStart();
		}
		if((firstFadeoutTime + fadeoutTime) >= (int)(timer->GetTimeFromGameStart()))
		{
			std::cout << "real" << std::endl;
			DrawRectangle(0, 0, 800, 600, BLACK);
			if (isSleep)
			{
				DrawText("Speep...", 300, 200, 30, WHITE);
			}
			else
			{
				DrawText("Toilet...", 300, 200, 30, WHITE);
			}
		}
		else
		{
			fadeTime = false;
		}
		
	}
}

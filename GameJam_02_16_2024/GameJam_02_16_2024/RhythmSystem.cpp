// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : RhythmSystem.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include <string>
#include "RhythmSystem.h"
#include "Timer.h"
#include "GlobalValues.h"
#include "GameStateManager.h"

RhythmSystem::RhythmSystem()
{
	std::cout << "Creating RhythmSystem..." << std::endl;
}

void RhythmSystem::ArrowTextureLoad(std::string path)
{
	Image arrowImage = LoadImage(path.c_str());
	Texture2D arrowTexture = LoadTextureFromImage(arrowImage);
	m_arrows.push_back(arrowTexture);
	UnloadImage(arrowImage);
}

void RhythmSystem::Init()
{
	std::cout << "Initializing RhythmSystem..." << std::endl;

	ArrowTextureLoad("Assets/white_arrow_right.png");
	ArrowTextureLoad("Assets/white_arrow_left.png");
	ArrowTextureLoad("Assets/white_arrow_down.png");
	ArrowTextureLoad("Assets/white_arrow_up.png");

	Image backgroundImage = LoadImage("Assets/minigamebackground.png");
	m_backgroundTexture = LoadTextureFromImage(backgroundImage);
	UnloadImage(backgroundImage);

	if (!whatbuffer.loadFromFile("Sound/what.ogg"))
	{
		std::cout << "what sound error";
	}
	if (!yahobuffer.loadFromFile("Sound/yaho.ogg"))
	{
		std::cout << "yaho sound error";
	}
}

void RhythmSystem::Update(float dt)
{
	m_timer += dt;
	if (m_readyFlag == false &&
		m_timer > m_readyTimer)
	{
		m_readyFlag = true;
	}
	if (m_startFlag == false &&
		m_timer > m_readyTimer + m_startTimer)
	{
		m_startFlag = true;

	}
	if (m_readyFlag == true && m_startFlag == true)
	{
		Play(dt);
	}
}

void RhythmSystem::Play(float dt)
{
	std::vector<KeyboardKey> keyline = m_keys[m_keyVIndex];

	if (IsKeyPressed(m_keys[m_keyVIndex][m_keyVVIndex]) == true)
	{
		std::cout << "Hit!\n";
		m_keyVVIndex++;
	}
	else
	{
		if (GetKeyPressed() != 0 && GetKeyPressed() != m_keys[m_keyVIndex][m_keyVVIndex])
		{
			std::cout << "Miss!\n";
			whatsound.setPlayingOffset(sf::seconds(1));
			whatsound.setBuffer(whatbuffer);
			whatsound.play();
			
			m_keyVVIndex = 0;
		}
	}

	if (m_keyVVIndex >= m_keys[0].size())
	{
		std::cout << "Next Line!\n";
		yahosound.setBuffer(yahobuffer);
		yahosound.setPlayingOffset(sf::seconds(1));
		yahosound.play();

		m_keyVVIndex = 0;
		m_keyVIndex++;
	}

	if (m_keyVIndex >= m_keys.size())
	{
		m_stageClearFlag = true;
		m_keyVIndex = 0;
	}

	if (m_timer > m_readyTimer + m_startTimer + m_limitTimer)
	{
		m_stageFailFlag = true;
	}

	if (m_stageFailFlag == true)
	{
		Reset();
		monitorState->SetMonitorStatus(MonitorStatus::Lobby);
	}

	if (m_stageClearFlag == true)
	{
		gameState->AddMoney(m_pointMulti * (monitorState->GetCurrentLevel() + 1));
		std::cout << gameState->GetMoney() << " Dollars" << std::endl;
		
		Reset();
		if (monitorState->GetCurrentLevel() == monitorState->GetLevelCounts() * static_cast<int>(MonitorNumber::Count) - 1)
		{
			gameStateManager->SetStateEnum(GameStateEnum::Ending);
			return;
		}
		monitorState->SetCurrentLevel(monitorState->GetCurrentLevel() + 1);
		
		if (monitorState->GetCurrentLevel() >= 3 && monitorState->GetMonitorNumber() >= MonitorNumber::Two)
		{
			monitorState->SetMonitorStatus(MonitorStatus::Lobby);
		}
		else if (monitorState->GetCurrentLevel() >= 6 && monitorState->GetMonitorNumber() >= MonitorNumber::Three)
		{
			monitorState->SetMonitorStatus(MonitorStatus::Lobby);
		}
		else if (monitorState->GetCurrentLevel() >= 9 && monitorState->GetMonitorNumber() >= MonitorNumber::Four)
		{
			monitorState->SetMonitorStatus(MonitorStatus::Lobby);
		}
		else if (monitorState->GetCurrentLevel() < 3)
		{
			monitorState->SetMonitorStatus(MonitorStatus::Lobby);
		}
		else
		{
			monitorState->SetMonitorStatus(MonitorStatus::Lobby);
			gameStateManager->SetStateEnum(GameStateEnum::Game);
		}
		GenerateKeys(monitorState->GetCurrentLevel());
	}
}

void RhythmSystem::Draw()
{
	DrawTexture(m_backgroundTexture, 0, 0, WHITE);
	if (m_readyFlag == false)
	{
		DrawText("Ready", WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 30, WHITE);
	} 
	else if (m_startFlag == false)
	{
		DrawText("Set", WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 30, WHITE);
	}
	else
	{
		m_warningRectHeight += static_cast<float>(WINDOW_HEIGHT) / m_limitTimer * GetFrameTime();
		DrawRectangle(0, 0, WINDOW_WIDTH, static_cast<int>(m_warningRectHeight), RED);

		int offsetX = 10;
		int offsetY = 20;

		int fontSize = 40;
		const int normalFontSize = 40;
		const int highlightedFontSize = 45;

		int gapX = 60;
		int gapY = 60;

		for(unsigned int i = 0; i < m_keys.size(); ++i)
		{ 
			for (unsigned int j = 0; j < m_keys[i].size(); ++j)
			{
				unsigned int keyValue = static_cast<unsigned int>(m_keys[i][j]);
				Color keyColor = WHITE;

				if (i == m_keyVIndex && j == m_keyVVIndex)
				{
					keyColor = BLUE;
				}
				else if (i < m_keyVIndex || i == m_keyVIndex && j < m_keyVVIndex)
				{
					keyColor = GREEN;
				}
				else
				{
					keyColor = WHITE;
				}

				if (i == m_keyVIndex && j == m_keyVVIndex)
				{
					fontSize = highlightedFontSize;
				}
				else
				{
					fontSize = normalFontSize;
				}

				if (keyValue >= 65 && keyValue <= 90)
				{
					char keyChar = 'a' + keyValue - 'a';
					std::string strChar{ keyChar };

					DrawText(strChar.c_str(), offsetX + gapX * j, offsetY + gapY * i, fontSize, keyColor);
				}

				if (keyValue == KEY_RIGHT)
				{
					DrawTexture(m_arrows[0], offsetX + gapX * j - 20, offsetY + gapY * i - 10, keyColor);
				}
				if (keyValue == KEY_LEFT)
				{
					DrawTexture(m_arrows[1], offsetX + gapX * j - 20, offsetY + gapY * i - 10, keyColor);
				}
				if (keyValue == KEY_DOWN)
				{
					DrawTexture(m_arrows[2], offsetX + gapX * j - 20, offsetY + gapY * i - 10, keyColor);
				}
				if (keyValue == KEY_UP)
				{
					DrawTexture(m_arrows[3], offsetX + gapX * j - 20, offsetY + gapY * i - 10, keyColor);
				}
			}
		}
	}
}

void RhythmSystem::GenerateKeys(int additional = 0)
{
	m_keys.clear();

	int dividedAdditional = additional / 2;

	unsigned int timeValue = static_cast<unsigned int>(timer->GetTimeFromWindowInit());

	srand(timeValue);

	for (unsigned int i = 0; i < m_keyVLength + dividedAdditional; ++i)
	{
		std::vector<KeyboardKey> newKeyLine;
		for (unsigned int j = 0; j < m_keyVVLength + dividedAdditional; ++j)
		{
			if (j % 5 == 0)
			{
				int randomNumber = rand();
				int keyNumber = randomNumber % 26;
				newKeyLine.push_back(static_cast<KeyboardKey>(KEY_A + keyNumber));
			}
			else
			{
				int randomNumber = rand();
				int keyNumber = randomNumber % 4;
				newKeyLine.push_back(static_cast<KeyboardKey>(KEY_RIGHT + keyNumber));
			}
		}
		m_keys.push_back(newKeyLine);
	}
}

void RhythmSystem::Reset()
{
	m_warningRectHeight = 0;
	m_readyFlag = false;
	m_startFlag = false;
	m_stageClearFlag = false;
	m_stageFailFlag = false;
	m_timer = 0.f;
	GenerateKeys();
}
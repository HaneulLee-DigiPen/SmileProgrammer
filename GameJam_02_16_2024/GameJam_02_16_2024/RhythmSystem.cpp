// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : RhythmSystem.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "RhythmSystem.h"
#include "Timer.h"
#include "GlobalValues.h"
#include <string>

RhythmSystem::RhythmSystem()
{
	std::cout << "Creating RhythmSystem..." << std::endl;
}

void RhythmSystem::Init()
{
	std::cout << "Initializing RhythmSystem..." << std::endl;
	GenerateKeys();
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
			m_keyVVIndex = 0;
		}
	}

	if (m_keyVVIndex >= m_keyVVLength)
	{
		std::cout << "Next Line!\n";
		m_keyVVIndex = 0;
		m_keyVIndex++;
	}

	if (m_keyVIndex >= m_keyVLength)
	{
		m_stageClearFlag = true;
	}

	if (m_timer > m_readyTimer + m_startTimer + m_limitTimer)
	{
		m_stageFailFlag = true;
	}

	if (m_stageFailFlag == true)
	{
		// Quit State
		// And maybe some penalty...?
		Reset();
	}

	if (m_stageClearFlag == true)
	{
		// Add score
		// Clear Check
		// Quit State
		Reset();
	}
}

void RhythmSystem::Draw() const
{
	if (m_readyFlag == false)
	{
		DrawText("Ready", WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 30, BLACK);
	} 
	else if (m_startFlag == false)
	{
		DrawText("Set", WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 30, BLACK);
	}
	else
	{
		int offsetX = WINDOW_WIDTH / 10;
		int offsetY = WINDOW_HEIGHT / 10;

		int fontSize = 30;
		const int normalFontSize = 30;
		const int highlightedFontSize = 40;

		int gapX = 50;
		int gapY = 70;

		for(unsigned int i = 0; i < m_keyVLength; ++i)
		{ 
			for (unsigned int j = 0; j < m_keyVVLength; ++j)
			{
				unsigned int keyValue = static_cast<unsigned int>(m_keys[i][j]);
				Color keyColor = BLACK;

				if (i == m_keyVIndex && j == m_keyVVIndex)
				{
					keyColor = RED;
				}
				else if (i == m_keyVIndex && j < m_keyVVIndex)
				{
					keyColor = GREEN;
				}
				else
				{
					keyColor = BLACK;
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
					DrawText("RR", offsetX + gapX * j, offsetY + gapY * i, fontSize, keyColor);
				}
				if (keyValue == KEY_LEFT)
				{
					DrawText("LL", offsetX + gapX * j, offsetY + gapY * i, fontSize, keyColor);
				}
				if (keyValue == KEY_DOWN)
				{
					DrawText("DD", offsetX + gapX * j, offsetY + gapY * i, fontSize, keyColor);
				}
				if (keyValue == KEY_UP)
				{
					DrawText("UU", offsetX + gapX * j, offsetY + gapY * i, fontSize, keyColor);
				}
			}
		}
	}
}

void RhythmSystem::GenerateKeys()
{
	m_keys.clear();

	unsigned int timeValue = static_cast<unsigned int>(timer->GetTimeFromWindowInit());

	srand(timeValue);

	for (unsigned int i = 0; i < m_keyVLength; ++i)
	{
		std::vector<KeyboardKey> newKeyLine;
		for (unsigned int j = 0; j < m_keyVVLength; ++j)
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

	for (unsigned int i = 0; i < m_keyVLength; ++i)
	{
		for (unsigned int j = 0; j < m_keyVVLength; ++j)
		{
			std::cout << m_keys[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void RhythmSystem::Reset()
{
	m_readyFlag = false;
	m_startFlag = false;
	m_stageClearFlag = false;
	m_timer = 0.f;
	GenerateKeys();
}
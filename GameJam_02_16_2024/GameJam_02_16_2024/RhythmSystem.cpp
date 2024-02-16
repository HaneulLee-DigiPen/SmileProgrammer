// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : RhythmSystem.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim


#include "RhythmSystem.h"
#include "Timer.h"

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
	if(m_readyFlag == false &&
		m_timer > m_readyTimer)
	{
		m_readyFlag = true;
	}
	if (m_startFlag == false &&
		m_timer > m_readyTimer + m_startTimer)
	{
		m_startFlag = true;
	}
	if (m_readyFlag == true && m_startFlag == true && 
		m_timer > m_readyTimer + m_startTimer + m_limitTimer)
	{
		Play(dt);
	}

	//Regenerate numbers
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
	{
		GenerateKeys();
	}
}

void RhythmSystem::Play(float dt)
{

}

void RhythmSystem::Draw() const
{
	
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
				newKeyLine.push_back(static_cast<KeyboardKey>(KEY_LEFT + keyNumber));
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
	m_keys.clear();
}
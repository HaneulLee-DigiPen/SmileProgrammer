// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : GameStateManager.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
	std::cout << "Creating GameStateManager..." << std::endl;
}

void GameStateManager::Init()
{
	std::cout << "Intializing GameStateManager..." << std::endl;
	// Add state pointers into "m_states" vector
}

void GameStateManager::SetStateEnum(GameStateEnum stateEnum)
{
	m_stateEnum = stateEnum;
	switch (m_stateEnum)
	{
	case GameStateEnum::MainMenu:
		// m_state = 
		break;
	case GameStateEnum::Game:
		// m_state = 
		break;
	case GameStateEnum::Monitor:
		// m_state = 
		break;
	case GameStateEnum::Ending:
		// m_state = 
		break;
	}
}

void GameStateManager::Draw() const
{
	// m_State -> Draw();
}

void GameStateManager::Update(float dt)
{
	// m_State -> Update();
}

void GameStateManager::Clear()
{
	for (GameState* state : m_states)
	{
		delete state;
	}
	m_states.clear();
}

GameStateEnum GameStateManager::GetStateEnum() const
{
	return m_stateEnum;
}

GameState* GameStateManager::GetState()
{
	return m_state;
}

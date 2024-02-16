// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : GameStateManager.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "GameStateManager.h"
#include "GameState.h"
#include "MonitorState.h"

GameState* gameState;
MonitorState* monitorState;

GameStateManager::GameStateManager()
{
	std::cout << "Creating GameStateManager..." << std::endl;

	// GameState* menuState = new MenuState();
	gameState = new GameState();
	monitorState = new MonitorState();
	// GameState* endingState = new EndingState();

	m_gameStates.resize(static_cast<int>(GameStateEnum::Count));

	// m_gameStates[static_cast<int>(GameStateEnum::Menu)] = menuState;
	m_gameStates[static_cast<int>(GameStateEnum::Game)] = gameState;
	m_gameStates[static_cast<int>(GameStateEnum::Monitor)] = monitorState;
	// m_gameStates[static_cast<int>(GameStateEnum::Ending)] = EndingState;
}

void GameStateManager::Init()
{
	std::cout << "Intializing GameStateManager..." << std::endl;

	m_gameStates.resize(static_cast<int>(GameStateEnum::Count));

	// m_gameStates[static_cast<int>(GameStateEnum::Menu)]->Init();
	m_gameStates[static_cast<int>(GameStateEnum::Game)]->Init();
	m_gameStates[static_cast<int>(GameStateEnum::Monitor)]->Init();
	// m_gameStates[static_cast<int>(GameStateEnum::Monitor)]->Init();
}

void GameStateManager::SetStateEnum(GameStateEnum stateEnum)
{
	m_gameStateEnum = stateEnum;
	m_gameState = m_gameStates[static_cast<int>(stateEnum)];
}

void GameStateManager::Update(float dt)
{
	m_gameState->Update(dt);
}

void GameStateManager::Draw() const
{
	m_gameState -> Draw();
}

void GameStateManager::Clear()
{
	for (State* state : m_gameStates)
	{
		delete state;
	}
	m_gameStates.clear();
}

GameStateEnum GameStateManager::GetStateEnum() const
{
	return m_gameStateEnum;
}

State* GameStateManager::GetState()
{
	return m_gameState;
}

// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : GameStateManager.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "GameStateManager.h"
#include "MenuState.h"
#include "GameState.h"
#include "MonitorState.h"
#include "EndingState.h"

MenuState* menuState;
GameState* gameState;
MonitorState* monitorState;
EndingState* endingState;


GameStateManager::GameStateManager()
{
	std::cout << "Creating GameStateManager..." << std::endl;

	MenuState* menuState = new MenuState();
	gameState = new GameState();
	monitorState = new MonitorState();
	endingState = new EndingState();


	m_gameStates.resize(static_cast<int>(GameStateEnum::Count));

	m_gameStates[static_cast<int>(GameStateEnum::MainMenu)] = menuState;
	m_gameStates[static_cast<int>(GameStateEnum::Game)] = gameState;
	m_gameStates[static_cast<int>(GameStateEnum::Monitor)] = monitorState;
	m_gameStates[static_cast<int>(GameStateEnum::Ending)] = endingState;
}

void GameStateManager::Init()
{
	std::cout << "Intializing GameStateManager..." << std::endl;

	m_gameStates.resize(static_cast<int>(GameStateEnum::Count));

	m_gameStates[static_cast<int>(GameStateEnum::MainMenu)]->Init();
	m_gameStates[static_cast<int>(GameStateEnum::Game)]->Init();
	m_gameStates[static_cast<int>(GameStateEnum::Monitor)]->Init();
	m_gameStates[static_cast<int>(GameStateEnum::Ending)]->Init();
}

void GameStateManager::SetStateEnum(GameStateEnum stateEnum)
{
	m_gameStateEnum = stateEnum;
	m_gameState = m_gameStates[static_cast<int>(stateEnum)];
}

void GameStateManager::Update(float dt)
{
	if (IsKeyPressed(KeyboardKey::KEY_BACKSPACE) == true)
	{
		SetStateEnum(GameStateEnum::Ending);
	}
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

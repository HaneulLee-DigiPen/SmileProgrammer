// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : StateManager.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "StateManager.h"

StateManager::StateManager()
{
	std::cout << "Creating StateManager..." << std::endl;
}

void StateManager::Init()
{
	std::cout << "Intializing StateManager..." << std::endl;
	// Add state pointers into "m_states" vector
}

void StateManager::SetStateEnum(StateEnum stateEnum)
{
	m_stateEnum = stateEnum;
	switch (m_stateEnum)
	{
	case StateEnum::MainMenu:
		// m_state = 
		break;
	case StateEnum::Game:
		// m_state = 
		break;
	case StateEnum::Monitor:
		// m_state = 
		break;
	case StateEnum::Ending:
		// m_state = 
		break;
	}
}

void StateManager::Draw() const
{
	// m_State -> Draw();
}

void StateManager::Update(float dt)
{
	// m_State -> Update();
}

void StateManager::Clear()
{
	for (State* state : m_states)
	{
		delete state;
	}
	m_states.clear();
}

StateEnum StateManager::GetStateEnum() const
{
	return m_stateEnum;
}

State* StateManager::GetState()
{
	return m_state;
}

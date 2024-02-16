#include "StateManager.h"
#include "GameState.h"

StateManager::StateManager()
{
	std::cout << "Creating StateManager..." << std::endl;
}

void StateManager::Init()
{
	std::cout << "Intializing StateManager..." << std::endl;
	// Add state pointers into "m_states" vector
	m_states.push_back(new GameState());
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
		m_state = m_states[0];
		m_state->Init();
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
	m_state -> Draw();
}

void StateManager::Update(float dt)
{
	m_state -> Update(dt);

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

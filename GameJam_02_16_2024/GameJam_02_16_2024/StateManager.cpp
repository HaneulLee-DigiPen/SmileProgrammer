#include "StateManager.h"

StateManager::StateManager()
{
	std::cout << "Creating StateManger..." << std::endl;

}

void StateManager::SetStateEnum(StateEnum stateEnum)
{
	m_stateEnum = stateEnum;
	switch (m_stateEnum)
	{
	case StateEnum::MainMenu:
		
		break;
	case StateEnum::Game:

		break;
	case StateEnum::Monitor:

		break;
	case StateEnum::Ending:

		break;
	}
}

void StateManager::Draw()
{
	m_State -> Draw();
}

void StateManager::Update(float dt)
{
	m_State -> Update();
}

StateEnum StateManager::GetStateEnum() const
{
	return m_stateEnum;
}

State* StateManager::GetState()
{
	return m_State;
}

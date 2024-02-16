#pragma once
#include <iostream>
#include <vector>

enum class StateEnum
{
	MainMenu = 0,
	Game,
	Monitor,
	Ending,
	Count
};

class State;

class StateManager
{
public:
	StateManager();

	void SetStateEnum(StateEnum stateEnum);
	void Update(float dt);

	StateEnum GetStateEnum() const;
	State* GetState();

private:
	StateEnum m_stateEnum = StateEnum::MainMenu;
	std::vector<State*> m_states{};
	State* m_State = nullptr;
};
// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : StateManager.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

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

	void Init();
	void SetStateEnum(StateEnum stateEnum);
	void Draw() const;
	void Update(float dt);
	void Clear();

	StateEnum GetStateEnum() const;
	State* GetState();

private:
	StateEnum m_stateEnum = StateEnum::MainMenu;
	std::vector<State*> m_states{};
	State* m_state = nullptr;
};

extern StateManager* stateManager;
// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : GameStateManager.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once
#include <iostream>
#include <vector>
#include "state.h"

enum class GameStateEnum
{
	MainMenu = 0,
	Game,
	Monitor,
	Ending,
	Count
};

class GameStateManager
{
public:
	GameStateManager();

	void Init();
	void SetStateEnum(GameStateEnum stateEnum);
	void Update(float dt);
	void Draw() const;
	void Clear();

	GameStateEnum GetStateEnum() const;
	State* GetState();

private:
	GameStateEnum m_gameStateEnum = GameStateEnum::MainMenu;
	std::vector<State*> m_gameStates{static_cast<int>(GameStateEnum::Count)};
	State* m_gameState = nullptr;
};

extern GameStateManager* gameStateManager;
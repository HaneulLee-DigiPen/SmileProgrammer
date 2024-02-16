// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : GameStateManager.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once
#include <iostream>
#include <vector>

enum class GameStateEnum
{
	MainMenu = 0,
	Game,
	Monitor,
	Ending,
	Count
};

class GameState;

class GameStateManager
{
public:
	GameStateManager();

	void Init();
	void SetStateEnum(GameStateEnum stateEnum);
	void Draw() const;
	void Update(float dt);
	void Clear();

	GameStateEnum GetStateEnum() const;
	GameState* GetState();

private:
	GameStateEnum m_stateEnum = GameStateEnum::MainMenu;
	std::vector<GameState*> m_states{};
	GameState* m_state = nullptr;
};

extern GameStateManager* gameStateManager;
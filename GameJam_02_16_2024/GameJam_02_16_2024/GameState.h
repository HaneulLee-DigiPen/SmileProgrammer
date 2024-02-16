// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : GameState.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once
#include "Player.h"
#include "State.h"
#include "raylib.h"
#include "Timer.h"
#include "Trash.h"
#include <vector>

class GameState : public State 
{
public:
	void Init() override;
	void Update(float dt) override;
	void Draw() override;
	void Clear() override;

private:
	void DrawBackground();
	void PlayerUpdate();
	void DrawPlayerStatus();
	void GenerateTrash();
	void DrawTrash();
	void DestroyTrash();

	int m_playerStatusTime = 5;
	int m_genTrashTime = 10;

	int m_checkDecreaseStatus = 2;
	int m_checkGenTrash = 2;

	Texture2D m_backgroundTexture;

	std::vector<Trash> trashVec;
};
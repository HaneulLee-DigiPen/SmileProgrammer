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

	int playerStatusTime = 5;
	int genTrashTime = 10;

	int checkDecreaseStatus = 2;
	int checkGenTrash = 2;

	Texture2D backgroundtexture;

	std::vector<Trash> trashVec;
};
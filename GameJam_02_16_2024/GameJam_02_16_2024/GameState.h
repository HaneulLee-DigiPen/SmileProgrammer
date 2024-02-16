#pragma once
#include "Player.h"
#include "State.h"
#include "raylib.h"
class GameState : State 
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
	void Clear() override;

private:
	void PlayerUpdate();
	void DrawPlayerStatus();
};
// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : EndingState.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once

#include "GameStateManager.h"

class EndingState : public State
{
public:
	void Init() override;
	void Update(float dt) override;
	void Draw() override;
	void Clear() override;
	
private:
	Texture2D m_endingTexture{};
};

extern EndingState* endingState;
// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : MonitorState.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once
#include "State.h"

class MonitorState : public State
{
public:
	void Init() override;
	void Update(float dt) override;
	void Draw() override;
	void Clear() override;

private:

};
// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : State.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once
class State
{
public:
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	virtual void Clear() = 0;
};
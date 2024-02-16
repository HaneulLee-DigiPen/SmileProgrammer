#pragma once
#include <raylib.h>
#include <iostream>

class Timer
{
public:
	Timer();

	void Update(float dt);
	void ResetTimeFromGameStart();
	void PrintOutTimeFromGameStart() const;

	float GetTimeFromWindowInit() const;
	float GetTimeFromGameStart() const;

private:
	float m_timeFromGameStart = 0.f;
};

extern Timer timer;
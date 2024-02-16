// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : Timer.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "Timer.h"

Timer::Timer()
{
	std::cout << "Creating Timer..." << std::endl;
}

void Timer::Init()
{
	std::cout << "Initializing Timer..." << std::endl;
}

void Timer::Update(float dt)
{
	m_timeFromGameStart += dt;
}

void Timer::ResetTimeFromGameStart()
{
	m_timeFromGameStart = 0.f;
}

void Timer::PrintOutTimeFromGameStart() const
{
	std::cout << m_timeFromGameStart << std::endl;
}

float Timer::GetTimeFromWindowInit() const
{
	return static_cast<float>(GetTime());
}

float Timer::GetTimeFromGameStart() const
{
	return m_timeFromGameStart;
}
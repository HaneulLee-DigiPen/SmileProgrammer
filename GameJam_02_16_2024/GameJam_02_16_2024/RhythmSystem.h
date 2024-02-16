// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : RhythmSystem.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class RhythmSystem
{
public:
	RhythmSystem();

	void Init();
	void Update(float dt);
	void Play(float dt);
	void Draw() const;
	void GenerateKeys();
	void Reset();
	
private:
	unsigned int m_keyVLength = 3;
	unsigned int m_keyVVLength = 10;
	std::vector<std::vector<KeyboardKey>> m_keys{};

	const float m_readyTimer = 1.0f;
	bool m_readyFlag = false;
	const float m_startTimer = 3.0f;
	bool m_startFlag = false;
	float m_timer = 0.f;
	float m_limitTimer = 10.f;
};

extern RhythmSystem* rhythmSystem;
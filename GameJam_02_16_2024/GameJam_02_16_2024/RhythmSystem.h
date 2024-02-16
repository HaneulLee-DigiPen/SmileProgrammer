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
	unsigned int m_keyVIndex = 0;
	unsigned int m_keyVVIndex = 0;

	std::vector<std::vector<KeyboardKey>> m_keys{};

	const float m_readyTimer = 1.0f;
	bool m_readyFlag = false;
	const float m_startTimer = 3.0f;
	bool m_startFlag = false;
	float m_timer = 0.f;
	float m_limitTimer = 60.f;

	

	bool m_stageClearFlag = false;
	bool m_stageFailFlag = false;
	int score = 100;


};

extern RhythmSystem* rhythmSystem;
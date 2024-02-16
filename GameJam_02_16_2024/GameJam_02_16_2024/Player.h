// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : Player.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once

class Player
{
public:
	void Update(float dt);

	void ChangeHungry(int point);
	void ChangeSleep(int point);
	void ChangeBathroom(int point);
	void ChangeThirsty(int point);

	int GetHungry();
	int GetSleep();
	int GetThirsty();
	int GetBathroom();
	
	bool enoughPoints();

private:
	int m_hungryPoint = 100;
	int m_sleepPoint = 100;
	int m_thirstyPoint = 100;
	int m_bathroomPoint = 100;

	int m_averagePoint = 100;

	const float m_fixedIncomeTimerLimit = 2.f;
	float m_incomeTimerLimit = 2.f;
	float m_incomeTimer = 0.f;

	void UpdateAveragePoint();
	
	

};

extern Player* player;
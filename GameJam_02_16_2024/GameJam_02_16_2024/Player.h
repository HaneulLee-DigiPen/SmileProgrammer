#pragma once
class Player
{
public:
	void ChangeHungry(int point);
	void ChangeSleep(int point);
	void ChangeBathroom(int point);
	void ChangeThirsty(int point);

private:
	int m_sleepPoint = 50;
	int m_thirstyPoint = 50;
	int m_bathroomPoint = 50;
	int m_hungryPoint = 50;
};

extern Player* player;
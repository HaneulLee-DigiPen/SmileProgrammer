#pragma once
class Player
{
public:
	void ChangeHungry(int point);
	void ChangeSleep(int point);
	void ChangeBathroom(int point);
	void ChangeThirsty(int point);

private:
	int sleepPoint = 50;
	int thirstyPoint = 50;
	int bathroomPoint = 50;
	int hungryPoint = 50;



};

extern Player player;
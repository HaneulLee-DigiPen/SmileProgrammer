#pragma once
class Player
{
public:
	void ChangeHungry(int point);
	void ChangeSleep(int point);
	void ChangeBathroom(int point);
	void ChangeThirsty(int point);

	int GetHungry() { return hungryPoint; }
	int GetSleep() { return sleepPoint; }
	int GetThirsty() { return thirstyPoint; }
	int GetBathroom() { return bathroomPoint; }

private:
	int sleepPoint = 100;
	int thirstyPoint = 100;
	int bathroomPoint = 100;
	int hungryPoint = 100;



};

extern Player player;
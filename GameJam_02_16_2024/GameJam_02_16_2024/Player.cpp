#include "Player.h"

void Player::ChangeHungry(int point)
{
	if (hungryPoint + point >= 100)
	{
		hungryPoint = 100;
	}
	else if (hungryPoint + point <= 0)
	{
		hungryPoint = 0;
	}
	else
	{
		hungryPoint += point;
	}
}

void Player::ChangeSleep(int point)
{
	if (sleepPoint + point >= 100)
	{
		sleepPoint = 100;
	}
	else if (sleepPoint + point <= 0)
	{
		sleepPoint = 0;
	}
	else
	{
		sleepPoint += point;
	}
}

void Player::ChangeBathroom(int point)
{
	if (bathroomPoint + point >= 100)
	{
		bathroomPoint = 100;
	}
	else if (bathroomPoint + point <= 0)
	{
		bathroomPoint = 0;
	}
	else
	{
		bathroomPoint += point;
	}
}

void Player::ChangeThirsty(int point)
{
	if (thirstyPoint + point >= 100)
	{
		thirstyPoint = 100;
	}
	else if (thirstyPoint + point <= 0)
	{
		thirstyPoint = 0;
	}
	else
	{
		thirstyPoint += point;
	}
}


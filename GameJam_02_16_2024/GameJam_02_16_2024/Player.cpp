#include "Player.h"

void Player::ChangeHungry(int point)
{
	hungryPoint += point;
}

void Player::ChangeSleep(int point)
{
	sleepPoint += point;
}

void Player::ChangeBathroom(int point)
{
	bathroomPoint += point;
}

void Player::ChangeThirsty(int point)
{
	thirstyPoint += point;
}


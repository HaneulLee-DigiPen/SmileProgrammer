#include "Player.h"

void Player::ChangeHungry(int point)
{
	m_hungryPoint += point;
}

void Player::ChangeSleep(int point)
{
	m_sleepPoint += point;
}

void Player::ChangeBathroom(int point)
{
	m_bathroomPoint += point;
}

void Player::ChangeThirsty(int point)
{
	m_thirstyPoint += point;
}


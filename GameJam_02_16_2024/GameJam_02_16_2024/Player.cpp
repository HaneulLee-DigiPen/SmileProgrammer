// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : Player.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "Player.h"

int Player::GetHungry() 
{ 
	return m_hungryPoint; 
}

int Player::GetSleep() 
{ 
	return m_sleepPoint; 
}

int Player::GetThirsty() 
{ 
	return m_thirstyPoint; 
}

int Player::GetBathroom() 
{ 
	return m_bathroomPoint; 
}

void Player::ChangeHungry(int point)
{
	if (m_hungryPoint + point >= 100)
	{
		m_hungryPoint = 100;
	}
	else if (m_hungryPoint + point <= 0)
	{
		m_hungryPoint = 0;
	}
	else
	{
		m_hungryPoint += point;
	}
}

void Player::ChangeSleep(int point)
{
	if (m_sleepPoint + point >= 100)
	{
		m_sleepPoint = 100;
	}
	else if (m_sleepPoint + point <= 0)
	{
		m_sleepPoint = 0;
	}
	else
	{
		m_sleepPoint += point;
	}
}

void Player::ChangeBathroom(int point)
{
	if (m_bathroomPoint + point >= 100)
	{
		m_bathroomPoint = 100;
	}
	else if (m_bathroomPoint + point <= 0)
	{
		m_bathroomPoint = 0;
	}
	else
	{
		m_bathroomPoint += point;
	}
}

void Player::ChangeThirsty(int point)
{
	if (m_thirstyPoint + point >= 100)
	{
		m_thirstyPoint = 100;
	}
	else if (m_thirstyPoint + point <= 0)
	{
		m_thirstyPoint = 0;
	}
	else
	{
		m_thirstyPoint += point;
	}
}


// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : Player.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "Player.h"
#include "GameStateManager.h"

void Player::Update(float dt)
{
	m_incomeTimer += dt;

	UpdateAveragePoint();
	
	m_incomeTimerLimit = m_fixedIncomeTimerLimit;
	// furniture bonus first (need to be fixed)
	if (gameState->GetCurtain() == true)
	{
		m_incomeTimerLimit -= 0.1f;
	}
	if (gameState->GetFan() == true)
	{
		m_incomeTimerLimit -= 0.1f;
	}
	if (gameState->GetShelf() == true)
	{
		m_incomeTimerLimit -= 0.1f;
	}
	if (gameState->GetBed() == true)
	{
		m_incomeTimerLimit -= 0.1f;
	}
	if (gameState->GetRefrigerator() == true)
	{
		m_incomeTimerLimit -= 0.2f;
	}
	if (gameState->GetAirConditioner() == true)
	{
		m_incomeTimerLimit -= 0.2f;
	}

	if (m_averagePoint < 25)
	{
		m_incomeTimerLimit += m_incomeTimerLimit * 0.75f;
	}
	else if (m_averagePoint < 50)
	{
		m_incomeTimerLimit += m_incomeTimerLimit * 0.5f;
	}
	else if (m_averagePoint < 75)
	{
		m_incomeTimerLimit += m_incomeTimerLimit * 0.25f;
	}

	if (m_incomeTimer >= m_incomeTimerLimit)
	{
		gameState->AddMoney(m_incomeMoney);
		m_incomeTimer = 0;
		std::cout << "Timer : " << m_incomeTimerLimit << std::endl;
		std::cout << gameState->GetMoney() << std::endl;
	}
}

void Player::SetAveragePoint(int point)
{
	m_averagePoint = point;
}

void Player::DoubleIncomeMoney()
{
	m_incomeMoney *= 2;
}

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

bool Player::enoughPoints()
{
	if (m_averagePoint >= 50)
	{
		return true;
	}
	else
	{
		return false;
	}
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

void Player::UpdateAveragePoint()
{
	m_averagePoint = (m_hungryPoint + m_sleepPoint + m_thirstyPoint + m_bathroomPoint) / 4;
}
#include "GameState.h"

Player player;

void GameState::Init()
{

}

void GameState::Update()
{
	PlayerUpdate();
}

void GameState::Draw()
{
	DrawPlayerStatus();
}

void GameState::Clear()
{

}


void GameState::PlayerUpdate()
{
	//10�ʿ� 1�ʾ� ��������.
	//Ÿ�̸� �����ϱ�.
	player.ChangeBathroom(-1);
	player.ChangeHungry(-1);
	player.ChangeSleep(-1);
	player.ChangeThirsty(-1);
}

void GameState::DrawPlayerStatus()
{
	
}
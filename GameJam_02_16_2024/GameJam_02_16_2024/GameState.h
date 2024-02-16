// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : GameState.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once
#include "Player.h"
#include "State.h"
#include "raylib.h"
#include "Timer.h"
#include "Trash.h"
#include <vector>

class GameState : public State 
{
public:
	void Init() override;
	void Update(float dt) override;
	void Draw() override;
	void Clear() override;

	void AddMoney(unsigned int money);
	void SpendMoney(unsigned int money);
	void SetMoney(unsigned int money);

	unsigned int GetMoney() const;

private:
	void DrawBackground();
	void PlayerUpdate(float dt);
	void DrawPlayerStatus();
	void GenerateTrash();
	void DrawTrash();
	void DestroyTrash();
	void DrawSmartPhoneUI();
	void UpdateSmartPhone();
	void DrawSmartPhoneIcon();
	void DrawSmartPhoneExplanation();
	void DrawSmartPhonePage_1();
	void DrawSmartPhonePage_2();
	void DrawSmartPhonePage_3();
	void DrawMoneyUI();

	void OrderFood();
	void DrawArriveFood();
	void DrawWaitTime();
	void GetFood();



	int m_playerStatusTime = 5;
	int m_genTrashTime = 10;

	int m_checkDecreaseStatus = 2;
	int m_checkGenTrash = 2;

	std::vector<Trash> m_trashVec;

	unsigned int m_money = 0;
	int m_smartphoneUI_posX = 670;
	int m_smartphoneUI_posY = 475;
	int m_smartphoneIcon_posX = 200;
	int m_smartphoneIcon_posY = 30;

	Texture2D m_backgroundTexture;
	Texture2D m_smartphoneUITexture;
	Texture2D m_smartphoneIconTexture;
	Texture2D m_smartphoneFrameTexture;
	Texture2D m_orderFoodTexture;
	Texture2D m_orderDrinkTexture;

	std::vector<Trash> trashVec;
	bool m_checkClickSmartPhone = false;
	int m_smartPhoneWhichIcon = 0;
	int m_smartPhonePage = 0;
	int m_pageWhichOne = 0;

	int m_option_X = 292;
	int m_option_W = 250;
	int m_option_H = 42;
	std::vector<int> optionHeight{175, 218, 261, 304, 347, 390, 433};

	bool m_canOrder = true;
	bool m_isFirst = false;
	float m_firstTime = 0;
	int m_orderTime = 5;
	bool m_isOrderArrive = false;
	bool m_isGetFood = false;
	bool m_isOrderWait = false;
	int m_orderPoint = 10;
	bool isFood = true;

	bool isPressed = false;
};
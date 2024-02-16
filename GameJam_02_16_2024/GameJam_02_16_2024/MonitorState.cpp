// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : MonitorState.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include <iostream>
#include "GameStateManager.h"
#include "RhythmSystem.h"
#include "GlobalValues.h"

void MonitorState::Init()
{
	std::cout << "Initializing MonitorState..." << std::endl;

	//Image monitorImage; = LoadImage("");
	//m_monitorTexture = LoadTextureFromImage(monitorImage);
	//UnloadImage(monitorImage);

	int buttonOffsetX = WINDOW_WIDTH / 4;
	int buttonOffsetY = WINDOW_HEIGHT / 2;
	int buttonWidth = 90;
	int buttonHeight = 50;

	for (unsigned int i = 0; i < m_levelCounts; ++i)
	{
		m_buttons.push_back(MonitorButton((i + 1) * buttonOffsetX, buttonOffsetY, buttonWidth, buttonHeight, WHITE));
	}
	
	m_rhythmSystem = new RhythmSystem();
	m_rhythmSystem->Init();
}

void MonitorState::Update(float dt)
{
	if (m_monitorStatus == MonitorStatus::Lobby)
	{
		LobbyUpdate(dt);
		if (IsKeyPressed(KeyboardKey::KEY_RIGHT_SHIFT) == true)
		{
			gameStateManager->SetStateEnum(GameStateEnum::Game);
		}
	}
	else if (m_monitorStatus == MonitorStatus::Work)
	{
		WorkUpdate(dt);
	}

	if (IsKeyPressed(KeyboardKey::KEY_RIGHT_SHIFT) == true)
	{
		gameStateManager->SetStateEnum(GameStateEnum::Game);
	}
}

void MonitorState::Draw()
{
	ClearBackground(Color{ 0, 0, 0, 255 });

	if (m_monitorStatus == MonitorStatus::Lobby)
	{
		LobbyDraw();
		DrawText("Press \"Right Shift\" to going back.", 60, 500, 40, WHITE);
	}
	else if (m_monitorStatus == MonitorStatus::Work)
	{
		WorkDraw();
	}
}

void MonitorState::Clear()
{
	delete m_rhythmSystem;
}

void MonitorState::LobbyUpdate(float dt)
{
	for(unsigned int i = 0; i < m_levelCounts; ++i)
	{
		m_buttons[i].Update(dt);
		if (m_buttons[m_currentLevel % m_levelCounts].IsMouseClicked() == true &&
			m_currentLevel == i + m_levelStartOffset)
		{
			m_monitorStatus = MonitorStatus::Work;
			m_rhythmSystem->GenerateKeys(m_currentLevel);
		}
	}
}

void MonitorState::WorkUpdate(float dt)
{
	m_rhythmSystem->Update(dt);
}

void MonitorState::LobbyDraw() const
{
	for (unsigned int i = 0; i < m_levelCounts; ++i)
	{
		m_buttons[i].Draw();
	}
}

void MonitorState::WorkDraw() const
{
	m_rhythmSystem->Draw();
}

void MonitorState::SetCurrentLevel(int level)
{
	m_currentLevel = level;
	if (m_currentLevel % 3 == 0)
	{
		m_levelStartOffset += m_levelCounts;
	}
}

void MonitorState::SetMonitorStatus(MonitorStatus monitorStatus)
{
	m_monitorStatus = monitorStatus;
}

void MonitorState::AddMonitor()
{
	if (m_monitorNum != MonitorNumber::Four)
	{
		m_monitorNum = static_cast<MonitorNumber>(static_cast<int>(m_monitorNum) + 1);
	}
}

unsigned int MonitorState::GetCurrentLevel() const
{
	return m_currentLevel;
}

unsigned int MonitorState::GetLevelCounts() const
{
	return m_levelCounts;
}

MonitorNumber MonitorState::GetMonitorNumber() const
{
	return m_monitorNum;
}

MonitorButton::MonitorButton(int x, int y, int width, int height, Color color)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_color = color;
}

void MonitorButton::Update(float dt)
{
	Vector2 mousePosition = GetMousePosition();

	const int m_colorGap = 30;
	unsigned char newGBValue = 255 - m_colorGap * (monitorState->GetCurrentLevel() / monitorState->GetLevelCounts());
	m_color = Color{ 255, newGBValue, newGBValue, 255 };

	if (mousePosition.x >= m_x && mousePosition.x <= m_x + m_width &&
		mousePosition.y >= m_y && mousePosition.y <= m_y + m_height)
	{
		m_isMouseOn = true;
		m_color.r = 150;
		m_color.a = 150;
	}
	else
	{
		m_isMouseOn = false;
		m_color.r = 255;
		m_color.a = 255;
	}

	if (m_isMouseOn && IsMouseButtonPressed(MouseButton::MOUSE_BUTTON_LEFT))
	{
		m_isMouseClicked = true;
		m_color.r = 100;
		m_color.a = 100;
	}
	else
	{
		m_isMouseClicked = false;
	}

}

void MonitorButton::Draw() const
{
	DrawRectangle(m_x, m_y, m_width, m_height, m_color);
}

bool MonitorButton::IsMouseClicked() const
{
	return m_isMouseClicked;
}
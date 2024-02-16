// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : MonitorState.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once
#include <raylib.h>
#include <vector>
#include "State.h"
#include "RhythmSystem.h"

enum class MonitorStatus {
	Lobby = 0,
	Work,
	Count
};

enum class MonitorNumber {
	One = 0,
	Two,
	Three,
	Four,
	Count
};

class MonitorButton
{
public:
	MonitorButton() = delete;
	MonitorButton(int x, int y, int width, int height, Color color);
	void Update(float dt);
	void Draw() const;

	bool IsMouseClicked() const;

private:
	int m_x = 0;
	int m_y = 0;
	int m_width = 50;
	int m_height = 50;
	Color m_color = { 255, 255, 255, 255 };

	bool m_isMouseOn = false;
	bool m_isMouseClicked = false;
};

class MonitorState : public State
{
public:
	void Init() override;
	void Update(float dt) override;
	void Draw() override;
	void Clear() override;

	void LobbyUpdate(float dt);
	void WorkUpdate(float dt);
	void LobbyDraw() const;
	void WorkDraw() const;

	void SetCurrentLevel(int level);
	void SetMonitorStatus(MonitorStatus monitorStatus);
	void AddMonitor();

	int unsigned GetCurrentLevel() const;
	int unsigned GetLevelCounts() const;
	MonitorNumber GetMonitorNumber() const;

private:
	Texture2D m_monitorTexture;
	int unsigned m_currentLevel = 0;
	int unsigned m_levelStartOffset = 0;
	const unsigned int m_levelCounts = 3;
	const unsigned int m_maxLevelCounts = 12;

	MonitorStatus m_monitorStatus = MonitorStatus::Lobby;
	MonitorNumber m_monitorNum = MonitorNumber::One;
	
	std::vector<MonitorButton> m_buttons;

	RhythmSystem* m_rhythmSystem;
};
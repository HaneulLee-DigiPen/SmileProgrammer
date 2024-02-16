#pragma once
#include "State.h"
#include "raylib.h"

class MenuState : public State
{
public:
	void Init() override;
	void Update(float dt) override;
	void Draw() override;
	void Clear() override;

private:
	void DrawBackground();
	void DrawTitle();
	void DrawExplanation();

	Texture2D m_backgroundTexture;

};
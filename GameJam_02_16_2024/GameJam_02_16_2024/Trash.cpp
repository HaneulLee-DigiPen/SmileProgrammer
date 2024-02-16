// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : Trash.cpp
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#include "Trash.h"

Trash::Trash(int PosX, int PosY) : posX(PosX), posY(PosY)
{
	Image image = LoadImage("Assets/trash.png");
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
}

Trash::~Trash()
{
	UnloadTexture(texture);
}

void Trash::Draw()
{
	DrawTexture(texture, posX, posY, WHITE);
}
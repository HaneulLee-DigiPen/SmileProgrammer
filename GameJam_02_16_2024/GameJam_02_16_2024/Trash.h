// Game Name : Smile, Programmer!
// Team Name : Sam Nam Mae
// File Name : Trash.h
// Authors : Haneul Lee, Yeaseul Lim, Junhyeong Kim

#pragma once
#include "raylib.h"

class Trash
{
public:
	Trash(int PosX, int PosY);
	~Trash();
	void Draw();
	int GetPosX() { return posX; }
	int GetPosY() { return posY; }
	
private:
	Texture2D texture;
	int posX;
	int posY;
};
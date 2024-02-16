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
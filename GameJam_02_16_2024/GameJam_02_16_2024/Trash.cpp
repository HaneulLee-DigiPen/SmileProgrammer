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
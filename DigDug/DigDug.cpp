// DigDug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "vld.h"
#include "MiniginGame.h"

int main()
{
	using namespace dae;

	MiniginGame *game = new MiniginGame();
	game->SetGameName(std::move("Dig Dug"));
	game->SetWindowDimensions(1280, 720);
	game->Run();

	delete game;
}

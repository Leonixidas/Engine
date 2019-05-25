// DigDug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "vld.h"
#include "MiniginGame.h"
#include "SceneManager.h"
#include "StartScreen.h"
#include "MultiplayerScreen.h"

int main()
{
	using namespace dae;

	MiniginGame *game = new MiniginGame();

	SceneManager::GetInstance().AddScene(std::make_shared<StartScreen>(game));
	SceneManager::GetInstance().AddScene(std::make_shared<MultiplayerScreen>());
	SceneManager::GetInstance().SetActiveScene(0);

	game->SetGameName(std::move("Dig Dug"));
	game->SetWindowDimensions(640, 480);
	game->Run();

	delete game;
}

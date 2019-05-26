// DigDug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "vld.h"
#include "MiniginGame.h"
#include "SceneManager.h"
#include "StartScreen.h"
#include "MultiplayerScreen.h"
#include "Level1.h"

int main()
{
	using namespace imp;

	std::shared_ptr<MiniginGame> game = std::shared_ptr<MiniginGame>(new MiniginGame());

	SceneManager::GetInstance().AddScene(std::shared_ptr<StartScreen>(new StartScreen(game)));
	SceneManager::GetInstance().AddScene(std::shared_ptr<MultiplayerScreen>(new MultiplayerScreen(game)));
	SceneManager::GetInstance().AddScene(std::shared_ptr<Level1>(new Level1(game)));
	SceneManager::GetInstance().SetActiveScene(0);

	game->SetGameName(std::move("Dig Dug"));
	game->SetWindowDimensions(480, 640);
	game->Run();
}

// DigDug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "vld.h"
#include "MiniginGame.h"
#include "SceneManager.h"
#include "TestScene.h"

int main()
{
	using namespace dae;

	SceneManager::GetInstance().AddScene(std::make_shared<TestScene>());
	SceneManager::GetInstance().SetActiveScene(0);

	MiniginGame *game = new MiniginGame();
	game->SetGameName(std::move("Dig Dug"));
	game->SetWindowDimensions(1280, 720);
	game->Run();

	delete game;
}

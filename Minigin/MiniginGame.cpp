#include "MiniginPCH.h"
#include "MiniginGame.h"
#include <thread>
#include <SDL.h>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Scene.h"
#include "TextureComponent.h"
#include "Transform.h"
#include "GameTime.h"


void dae::MiniginGame::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		m_Name.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		int(m_WindowWidth),
		int(m_WindowHeight),
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void dae::MiniginGame::LoadGame() const
{
	SceneManager::GetInstance().RootInitialize();
}

void dae::MiniginGame::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void dae::MiniginGame::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		float lag = 0.f;
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();
		auto& gameTime = GameTime::GetInstance();
		m_MsPerFrame = gameTime.GetFixedElapsed();

		bool doContinue = true;
		m_GameState = GameStates::LOOPING;
		while (doContinue && m_GameState == GameStates::LOOPING)
		{
			float deltaTime = gameTime.CalulateElapsedTime();
			lag += deltaTime;

			doContinue = input.ProcessInput();
			while (lag >= m_MsPerFrame)
			{
				sceneManager.FixedUpdate();
				lag -= m_MsPerFrame;
			}

			sceneManager.Update();
			renderer.Render();
		}
	}

	Cleanup();
}

void dae::MiniginGame::SetWindowDimensions(float width, float height)
{
	m_WindowWidth = width;
	m_WindowHeight = height;
}

void dae::MiniginGame::SetGameName(const std::string & name)
{
	m_Name = std::move(name);
}

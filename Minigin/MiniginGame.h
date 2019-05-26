#pragma once

struct SDL_Window;

namespace imp
{
	class MiniginGame
	{
		float m_MsPerFrame = 0; //16 for 60 fps, 33 for 30 fps
		SDL_Window* m_Window{};
		float m_WindowWidth = 640.f;
		float m_WindowHeight = 480.f;
		std::string m_Name = "Programming 4 Assignment";

		bool m_IsExiting = false;
		int m_GameMode = 0;

	public:
		void Initialize();
		void Cleanup();
		void Run();

		void SetWindowDimensions(float width, float height);
		void SetGameName(const std::string& name);

		void SetGameMode(int gamemode) { m_GameMode = gamemode; }
		int GetGameMode() { return m_GameMode; }

		void SetGameState(bool isExiting) { m_IsExiting = isExiting; }

		glm::vec2 GetWindowDimensions() { return { m_WindowWidth, m_WindowHeight }; }
		const SDL_Window& GetGameWindow() { return *m_Window; }
	};
}
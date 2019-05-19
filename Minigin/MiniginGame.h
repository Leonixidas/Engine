#pragma once

struct SDL_Window;

namespace dae
{
	class MiniginGame
	{
		const float m_MsPerFrame = 16.f; //16 for 60 fps, 33 for 30 fps
		SDL_Window* m_Window{};
		float m_WindowWidth = 640.f;
		float m_WindowHeight = 480.f;
		std::string m_Name = "Programming 4 Assignment";
	public:
		void Initialize();
		void LoadGame() const;
		void Cleanup();
		void Run();
		void SetWindowDimensions(float width, float height);
		void SetGameName(const std::string& name);
		const SDL_Window& GetGameWindow() { return *m_Window; }
	};
}
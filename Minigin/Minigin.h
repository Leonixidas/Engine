#pragma once

struct SDL_Window;

namespace dae
{
	class Minigin
	{
		const float m_MsPerFrame = 16.f; //16 for 60 fps, 33 for 30 fps
		SDL_Window* window{};
	public:
		void Initialize();
		void LoadGame() const;
		void Cleanup();
		void Run();
	};
}
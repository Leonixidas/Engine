#pragma once
#include "Singleton.h"
#include "MiniginGame.h"
#include <chrono>

namespace dae
{
	class GameTime final : public Singleton<GameTime>
	{
	public:
		GameTime()
		{
			m_PreviousTime = std::chrono::high_resolution_clock::now();
		}
		~GameTime() = default;
		float GetElapsedSec() { return m_DeltaTime; }
		float GetFixedElapsed() { return m_FIXEDTIME; }
		float GetFPS() { return m_FPS; }
	private:
		friend MiniginGame;
		float CalulateElapsedTime()
		{
			m_CurrentTime = std::chrono::high_resolution_clock::now();
			m_DeltaTime = std::chrono::duration<float>(m_CurrentTime - m_PreviousTime).count();
			m_PreviousTime = m_CurrentTime;
			m_AccumulatedTime += m_DeltaTime;
			++m_Frames;
			m_FPS = 1 / (m_AccumulatedTime / m_Frames);
			if (m_Frames > 1000)
			{
				m_Frames = 0;
				m_AccumulatedTime = 0.f;
			}
			return m_DeltaTime;
		}

		float m_FIXEDTIME = 0.16f;
		float m_DeltaTime = 0.0f;
		float m_AccumulatedTime = 0.f;
		unsigned int m_Frames = 0;
		float m_FPS = 0.f;

		std::chrono::time_point<std::chrono::steady_clock> m_PreviousTime = {};
		std::chrono::time_point<std::chrono::steady_clock> m_CurrentTime = {};
		
	};
}


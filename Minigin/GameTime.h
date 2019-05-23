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
	private:
		friend MiniginGame;
		float CalulateElapsedTime()
		{
			m_CurrentTime = std::chrono::high_resolution_clock::now();
			m_DeltaTime = std::chrono::duration<float>(m_CurrentTime - m_PreviousTime).count();
			m_PreviousTime = m_CurrentTime;
			return m_DeltaTime;
		}

		float m_FIXEDTIME = 0.16f;
		float m_DeltaTime = 0.0f;
		std::chrono::time_point<std::chrono::steady_clock> m_PreviousTime = {};
		std::chrono::time_point<std::chrono::steady_clock> m_CurrentTime = {};
		
	};
}


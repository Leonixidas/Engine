#pragma once
#include <Scene.h>

namespace imp
{
	class MultiplayerScreen :	public Scene
	{
	public:
		MultiplayerScreen(const std::shared_ptr<MiniginGame>& game);
		~MultiplayerScreen() = default;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render() const override;

	private:

		void DeselectObject();
		void SelectObject();

		std::vector<std::shared_ptr<GameObject>> m_Objects;
		std::shared_ptr<GameObject> m_FPSText;
		int m_objectIndex = 0;
	};
}


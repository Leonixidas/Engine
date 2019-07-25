#pragma once
#include <Scene.h>
namespace imp
{
	class GameObject;

	class StartScreen final :	public Scene
	{
	public:
		StartScreen(const std::shared_ptr<MiniginGame>& game);
		~StartScreen() = default;

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


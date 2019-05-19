#pragma once
#include "Scene.h"
namespace dae
{
	class TestScene final : public Scene
	{
	public:
		TestScene();
		~TestScene() = default;

		virtual void Initialize();
		virtual void Update(float elapsedSec);
		virtual void Render() const;

	private:
		std::shared_ptr<GameObject> m_Logo = nullptr;
		std::shared_ptr<GameObject> m_FPSText = nullptr;
	};
}


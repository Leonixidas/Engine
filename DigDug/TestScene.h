#pragma once
#include "Scene.h"
namespace dae
{
	class TestScene final : public Scene
	{
	public:
		TestScene();
		~TestScene() = default;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render() const override;


	private:
		std::shared_ptr<GameObject> m_Logo = nullptr;
		std::shared_ptr<GameObject> m_FPSText = nullptr;
	};
}


#pragma once
#include "Singleton.h"

namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		void Update(float elapsedSec);
		void Render();
		void SetActiveScene(const unsigned int id);
		Scene& GetActiveScene();
		void AddScene(const std::shared_ptr<Scene>& scene);

	private:
		std::vector<std::shared_ptr<Scene>> m_Scenes;
		std::shared_ptr<Scene> m_ActiveScene;
	};

}

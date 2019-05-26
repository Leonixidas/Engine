#pragma once
#include "Singleton.h"

namespace imp
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		void Update();
		void FixedUpdate() {}
		void Render();
		void RootInitialize();
		void SetActiveScene(const unsigned int id);
		void SetActiveScene(const std::string& name);
		void GoToPreviousScene();
		Scene& GetActiveScene();
		void AddScene(const std::shared_ptr<Scene>& scene);

	private:
		std::vector<std::shared_ptr<Scene>> m_Scenes;
		std::shared_ptr<Scene> m_ActiveScene;
		std::shared_ptr<Scene> m_PreviousScene;
	};

}

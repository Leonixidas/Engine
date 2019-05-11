#pragma once

namespace dae
{
	class GameObject;
	class SceneRenderer;

	class Scene
	{
	public:
		void RootUpdate(float elapsedSec);
		void Render() const;
		int GetID() { return m_ID; }
		SceneRenderer& GetSceneRenderer();

		virtual ~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	protected:
		void Update(float ) {};
		void Add(const std::shared_ptr<GameObject>& object);
		explicit Scene(const std::string& name);

	private: 
		int m_ID;
		std::unique_ptr<SceneRenderer> m_SceneRenderer;
		std::string m_Name{};
		std::vector<std::shared_ptr<GameObject>> m_Objects{};

		static unsigned int idCounter; 
	};

}

#pragma once

namespace dae
{
	class GameObject;
	class SceneRenderer;

	class Scene
	{
	public:
		virtual ~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

		int GetID() { return m_ID; }

		// These are needed to make the inherited scenes work. This will add some automated functionality for the derived scenes
		// for example, the user won't need to call update for the added objects or other stuff
		void RootUpdate();
		void RootRender() const;
		void RootInitialize();

	protected:
		// These are the functions that will be used for the derived class. 
		// I know we need to prefer composition over inheritance but,
		// with this little setup some things will be automated and the user won't need to bother with these kinds of things
		// This set up is mostly inspired by the *****OVERLORD ENGINE*****, I first thought of other ways to use the scene class
		// but I was bothered by the creation of them. It's way easier and has a better overview by just making a derived class from this one
		// instead of calling the scene manager and creating one and then using the return value to add objects etc. (I like structure)
		// that's why I used this set up for the scenes
		virtual void Update() {};
		virtual void Render() const {};
		virtual void Initialize() {};

		void AddGameObject(const std::shared_ptr<GameObject>& object);

		explicit Scene(const std::string& name);

	private: 
		std::vector<std::shared_ptr<GameObject>> m_Objects{};
		std::string m_Name{};
		std::shared_ptr<SceneRenderer> m_pSceneRenderer;

		static unsigned int idCounter; 
		int m_ID;
	};

}

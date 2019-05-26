#pragma once

namespace imp
{
	class BaseComponent;
	class Transform;

	class GameObject final
	{
	public:
		GameObject();
		GameObject(const std::shared_ptr<GameObject>& parent);
		~GameObject();

		virtual void Update();

		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) noexcept = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other)noexcept = delete;

		Transform& GetTransform() { return *m_Transform; }
		
		const std::vector<std::shared_ptr<GameObject>>& GetChildren() { return m_Children; }

		// Components
		//-----------
		template <class T>
		T* GetComponent();

		template <class T>
		bool HasComponent();

		void AddComponent(BaseComponent* component);

		// Children
		//---------
		void AddChild(const std::shared_ptr<GameObject>& child);
		void DeleteChild(const std::shared_ptr<GameObject>& child);

	private:
		std::vector<BaseComponent*> m_Components;
		std::vector<std::shared_ptr<GameObject>> m_Children;
		std::shared_ptr<Transform> m_Transform;
		std::shared_ptr<GameObject> m_Parent = nullptr;
	};
}

template <class T>
T* imp::GameObject::GetComponent()
{
	for (auto component : m_Components)
	{
		if (typeid(*component) == typeid(T))
		{
			return dynamic_cast<T*>(component);
		}
	}

	return nullptr;
}

template <class T>
bool imp::GameObject::HasComponent()
{
	for (auto c : m_Components)
	{
		if (typeid(*c) == typeid(T))
			return true;
	}

	return false;
}
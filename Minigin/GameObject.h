#pragma once

namespace dae
{
	class BaseComponent;
	class Transform;

	class GameObject final
	{
	public:
		GameObject();
		~GameObject();

		virtual void Update(float ) {};

		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) noexcept = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other)noexcept = delete;

		Transform& GetTransform() { return *m_Transform; }

		// Components
		//-----------
		template <class T>
		T& GetComponent();

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
	};
}

template <class T>
T& dae::GameObject::GetComponent()
{
	for (auto component : m_Components)
	{
		if (typeid(*component) == typeid(T))
		{
			return *dynamic_cast<T*>(component);
		}
	}

	throw std::exception("This gameObject doesn't have a component of this type");
}

template <class T>
bool dae::GameObject::HasComponent()
{
	for (auto c : m_Components)
	{
		if (typeid(*c) == typeid(T))
			return true;
	}

	return false;
}
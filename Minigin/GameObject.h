#pragma once
#include "SceneObject.h"


namespace dae
{
	class BaseComponent;
	class Transform;

	class GameObject final : public SceneObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Update(float elapsedSec) override;
		virtual void Render()const override;

		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) noexcept = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other)noexcept = delete;

		Transform& GetTransform() { return *m_Transform; }

		template <class T>
		T& GetComponent();
		void AddComponent(BaseComponent* component);

	private:
		std::vector<BaseComponent*> m_Components;
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
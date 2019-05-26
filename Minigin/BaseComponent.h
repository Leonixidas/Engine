#pragma once

namespace imp
{
	class GameObject;
	class BaseComponent
	{
	public:
		BaseComponent(const std::shared_ptr<GameObject>& owner);
		virtual ~BaseComponent() = default;

		virtual void Update() {};
		const std::shared_ptr<GameObject>& GetGameObject() { return m_pGameObject; }

	protected:
		std::shared_ptr<GameObject> m_pGameObject;
	};
}


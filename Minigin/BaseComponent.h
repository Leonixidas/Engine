#pragma once

namespace dae
{
	class GameObject;
	class BaseComponent
	{
	public:
		BaseComponent(const std::shared_ptr<GameObject>& owner);
		virtual ~BaseComponent() = default;

		virtual void Update(float ) {};
		virtual void Render() const {};

	protected:
		std::shared_ptr<GameObject> m_pGameObject;
	};
}


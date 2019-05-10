#pragma once

namespace dae
{
	class GameObject;
	class BaseComponent
	{
	public:
		BaseComponent(const std::shared_ptr<GameObject>& owner);
		virtual ~BaseComponent() = default;

		virtual void Update(float elapsedSec) {};
		virtual void Render() const {};

		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) noexcept = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) noexcept = delete;

	protected:
		std::shared_ptr<GameObject> m_GameObject;
	};
}


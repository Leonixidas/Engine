#pragma once
#include "BaseComponent.h"

namespace dae
{
	enum class CollisionType
	{
		STATIC,
		DYNAMIC
	};

	class ColliderComponent final : public BaseComponent
	{
	public:
		ColliderComponent(const std::shared_ptr<GameObject>& owner);
		~ColliderComponent() = default;

		void OnOverlapEnter(BaseComponent& otherComponent, GameObject& other);

		glm::vec2 GetColliderSizes() { return m_ColliderSizes; }

		void SetCollisionType(const CollisionType& type) { m_CollisionType = type; }

	private:
		glm::vec2 m_ColliderSizes;
		CollisionType m_CollisionType = CollisionType::STATIC;
	};
}

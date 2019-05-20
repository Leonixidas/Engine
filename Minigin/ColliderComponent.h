#pragma once
#include "BaseComponent.h"

namespace dae
{
	class ColliderComponent final : public BaseComponent
	{
	public:
		ColliderComponent(const std::shared_ptr<GameObject>& owner);
		~ColliderComponent() = default;
		void OnOverlapEnter(BaseComponent& otherComponent, GameObject& other);

	private: 
		glm::vec2 m_ColliderSizes;
	};
}

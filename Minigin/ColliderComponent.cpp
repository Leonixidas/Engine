#include "MiniginPCH.h"
#include "ColliderComponent.h"

dae::ColliderComponent::ColliderComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
{
}

void dae::ColliderComponent::OnOverlapEnter(BaseComponent & , GameObject & )
{
}

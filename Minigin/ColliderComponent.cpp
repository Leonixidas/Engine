#include "MiniginPCH.h"
#include "ColliderComponent.h"

imp::ColliderComponent::ColliderComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
{
}

void imp::ColliderComponent::OnOverlapEnter(BaseComponent & , GameObject & )
{
}

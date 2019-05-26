#include "MiniginPCH.h"
#include "BaseComponent.h"

imp::BaseComponent::BaseComponent(const std::shared_ptr<GameObject>& owner)
	: m_pGameObject(owner)
{
}

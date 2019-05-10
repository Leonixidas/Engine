#include "MiniginPCH.h"
#include "BaseComponent.h"

dae::BaseComponent::BaseComponent(const std::shared_ptr<GameObject>& owner)
	: m_GameObject(owner)
{
}

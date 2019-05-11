#include "MiniginPCH.h"
#include "RenderComponent.h"


dae::RenderComponent::RenderComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
{
}

void dae::RenderComponent::Render() const
{
}
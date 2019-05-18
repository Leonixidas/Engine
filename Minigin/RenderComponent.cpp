#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "TextureComponent.h"
#include "GameObject.h"
#include "Renderer.h"


dae::RenderComponent::RenderComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
{
}

void dae::RenderComponent::Render() const
{
	TextureComponent texComp = m_pGameObject->GetComponent<TextureComponent>();
	Renderer::GetInstance().RenderTexture(texComp.GetTexture(), texComp.GetSourceRect(), texComp.GetDestRect());
}
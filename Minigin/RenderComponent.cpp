#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "TextureComponent.h"
#include "Transform.h"
#include "GameObject.h"
#include "Renderer.h"


dae::RenderComponent::RenderComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
{
}

void dae::RenderComponent::Render() const
{
	TextureComponent *texComp = m_pGameObject->GetComponent<TextureComponent>();
	if (texComp == nullptr) return;
	glm::vec3 pos = m_pGameObject->GetTransform().GetPosition();
	SDL_Rect dest{texComp->GetDestRect()};
	dest.x = int(pos.x);
	dest.y = int(pos.y);
	
	Renderer::GetInstance().RenderTexture(texComp->GetTexture(), texComp->GetSourceRect(), dest);
}
#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Transform.h"


dae::TextureComponent::TextureComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
	, m_Width(0.f)
	, m_Height(0.f)
{
}

void dae::TextureComponent::Update(float )
{
}

void dae::TextureComponent::Render() const
{
	if(m_pTexture != nullptr)
	{
		glm::vec3 pos = m_GameObject->GetTransform().GetPosition();
		Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y, m_Width, m_Height);
	}
}

void dae::TextureComponent::SetTexture(const std::string & assetFile)
{
	m_pTexture = std::move(ResourceManager::GetInstance().LoadTexture(assetFile));
	int w{}, h{};
	if (m_pTexture->GetDimensionsFromTexture(w, h) == 0)
	{
		m_Width = float(w);
		m_Height = float(h);
	}
}

void dae::TextureComponent::SetWidthAndHeight(const float & width, const float & height)
{
	m_Width = width;
	m_Height = height;
}
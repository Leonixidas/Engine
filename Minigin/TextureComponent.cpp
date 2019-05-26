#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Texture2D.h"
#include "Renderer.h"
#include "Transform.h"


imp::TextureComponent::TextureComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
	, m_TextureDimensions()
	, m_SourceRect()
	, m_DestRect()
{
}

void imp::TextureComponent::SetTexture(const std::string & assetFile)
{
	m_pTexture = std::move(ResourceManager::GetInstance().LoadTexture(assetFile));
	int w{}, h{};
	if (m_pTexture->GetDimensionsFromTexture(w, h) == 0)
	{
		m_TextureDimensions.x = float(w);
		m_TextureDimensions.y = float(h);
	}
	m_SourceRect.w = w;
	m_SourceRect.h = h;

	m_DestRect.w = w;
	m_DestRect.h = h;
}

void imp::TextureComponent::SetTexture(const std::shared_ptr<Texture2D>& texture)
{
	m_pTexture = texture;
}

void imp::TextureComponent::SetTextureWidthAndHeight(const float & width, const float & height)
{
	m_TextureDimensions.x = width;
	m_TextureDimensions.y = height;
	m_SourceRect.w = int(width);
	m_SourceRect.h = int(height);
	m_DestRect.w = int(width);
	m_DestRect.h = int(height);
}

void imp::TextureComponent::SetSourceRect(const glm::vec2& pos, const float& width, const float& height)
{
	m_SourceRect.x = int(pos.x);
	m_SourceRect.y = int(pos.y);
	m_SourceRect.w = int(width);
	m_SourceRect.h = int(height);
}

void imp::TextureComponent::SetDestRect(const glm::vec2& pos, const float& width, const float& height)
{
	m_DestRect.x = int(pos.x);
	m_DestRect.y = int(pos.y);
	m_DestRect.w = int(width);
	m_DestRect.h = int(height);
}
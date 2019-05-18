#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Texture2D.h"
#include "Renderer.h"
#include "Transform.h"


dae::TextureComponent::TextureComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
	, m_TextureWidth(0.f)
	, m_TextureHeight(0.f)
	, m_SourceRect()
	, m_DestRect()
{
}

void dae::TextureComponent::SetTexture(const std::string & assetFile)
{
	m_pTexture = std::move(ResourceManager::GetInstance().LoadTexture(assetFile));
	int w{}, h{};
	if (m_pTexture->GetDimensionsFromTexture(w, h) == 0)
	{
		m_TextureWidth = float(w);
		m_TextureHeight = float(h);
	}
}

void dae::TextureComponent::SetTexture(const std::shared_ptr<Texture2D>& texture)
{
	m_pTexture = texture;
}

void dae::TextureComponent::SetTextureWidthAndHeight(const float & width, const float & height)
{
	m_TextureWidth = width;
	m_TextureHeight = height;
}

void dae::TextureComponent::SetSourceRect(const float& x, const float& y, const float& width, const float& height)
{
	m_SourceRect.x = int(x);
	m_SourceRect.y = int(y);
	m_SourceRect.w = int(width);
	m_SourceRect.h = int(height);
}

void dae::TextureComponent::SetDestRect(const float& x, const float& y, const float& width, const float& height)
{
	m_DestRect.x = int(x);
	m_DestRect.y = int(y);
	m_DestRect.w = int(width);
	m_DestRect.h = int(height);
}
#include "MiniginPCH.h"
#include <SDL_ttf.h>
#include <SDL.h>

#include "TextComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture2D.h"
#include "TextureComponent.h"
#include "GameObject.h"
#include "Font.h"


dae::TextComponent::TextComponent(const std::shared_ptr<GameObject>& owner)
	: TextComponent(owner, std::move(SDL_Color{ 255,255,255 }), std::move("Text"), std::move("Lingua.otf"))
{
}

dae::TextComponent::TextComponent(const std::shared_ptr<GameObject>& owner, 
								  const SDL_Color & color, const std::string & text, 
								  const std::string & fontFilePath, 
								  const int & size)
	: BaseComponent(owner)
{
	m_Text = std::move(text);
	m_FontSize = size;
	m_spFont = ResourceManager::GetInstance().LoadFont(fontFilePath, size);
	m_spColor = std::make_shared<SDL_Color>(color);
	CreateTextureFromFont();
}

void dae::TextComponent::SetColor(const SDL_Color & color)
{
	m_spColor = std::make_shared<SDL_Color>(color);
	CreateTextureFromFont();
}

void dae::TextComponent::SetText(const std::string & text)
{
	m_Text = std::move(text);
	CreateTextureFromFont();
}

void dae::TextComponent::SetFont(const std::string & filePath, int size)
{
	m_spFont = ResourceManager::GetInstance().LoadFont(filePath, size);
	CreateTextureFromFont();
}

void dae::TextComponent::CreateTextureFromFont()
{
	TextureComponent texComp = m_pGameObject->GetComponent<TextureComponent>();

	const auto surface = TTF_RenderText_Blended(m_spFont->GetFont(), m_Text.c_str(), *m_spColor);
	if (surface == nullptr)
		throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
	auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surface);
	if (texture == nullptr)
		throw std::runtime_error(std::string("Create texture from surface failed: ") + SDL_GetError());

	texComp.SetTexture(std::make_shared<Texture2D>(texture));
	texComp.SetTextureWidthAndHeight(float(surface->w), float(surface->h));

	SDL_FreeSurface(surface);
}

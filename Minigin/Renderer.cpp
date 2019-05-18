 #include "MiniginPCH.h"
#include "Renderer.h"
#include <SDL.h>
#include "SceneManager.h"
#include "Texture2D.h"
#include "SDL_rect.h"

void dae::Renderer::Init(SDL_Window * window)
{
	m_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}
}

void dae::Renderer::Render()
{
	SDL_RenderClear(m_Renderer);

	SceneManager::GetInstance().Render();
	
	SDL_RenderPresent(m_Renderer);
}

void dae::Renderer::Destroy()
{
	if (m_Renderer != nullptr)
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
}

void dae::Renderer::RenderTexture(const Texture2D & texture, const SDL_Rect & sourceRect, const SDL_Rect & destRect) const
{
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), &sourceRect, &destRect);
}

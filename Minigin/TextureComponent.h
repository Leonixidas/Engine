#pragma once
#include "BaseComponent.h"
#include "SDL_rect.h"


namespace dae
{
	class Texture2D;

	class TextureComponent final : public BaseComponent
	{
	public:
		TextureComponent(const std::shared_ptr<GameObject>& owner);
		~TextureComponent() = default;

		void SetTexture(const std::string& assetFile);
		void SetTexture(const std::shared_ptr<Texture2D>& texture);
		void SetTextureWidthAndHeight(const float& width, const float& height);

		void SetSourceRect(const float& x, const float& y, const float& width, const float& height);
		void SetDestRect(const float& x, const float& y, const float& width, const float& height);
		
		const SDL_Rect& GetSourceRect() const { return m_SourceRect; }
		const SDL_Rect& GetDestRect() const { return m_DestRect; }

		const float GetTextureWidth() const { return m_TextureWidth; }
		const float GetTextureHeight() const { return m_TextureHeight; }

		const Texture2D& GetTexture() const { return *m_pTexture; }

	private:
		std::shared_ptr<Texture2D> m_pTexture;
		float m_TextureWidth;
		float m_TextureHeight;
		SDL_Rect m_SourceRect;
		SDL_Rect m_DestRect;
	};
}


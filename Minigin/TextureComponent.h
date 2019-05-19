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

		void SetSourceRect(const glm::vec2& pos, const float& width, const float& height);
		void SetDestRect(const glm::vec2& pos, const float& width, const float& height);
		
		const SDL_Rect& GetSourceRect() const { return m_SourceRect; }
		const SDL_Rect& GetDestRect() const { return m_DestRect; }

		const glm::vec2& GetTextureSizes() { return m_TextureDimensions; }

		const Texture2D& GetTexture() const { return *m_pTexture; }

	private:
		std::shared_ptr<Texture2D> m_pTexture;
		glm::vec2 m_TextureDimensions;
		SDL_Rect m_SourceRect;
		SDL_Rect m_DestRect;
	};
}


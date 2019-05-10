#pragma once
#include "BaseComponent.h"
struct SDL_Color;

namespace dae
{
	class Font;
	class Texture2D;

	class TextComponent final : public BaseComponent
	{
		std::string m_Text;
		std::shared_ptr<Font> m_spFont;
		std::shared_ptr<SDL_Color> m_spColor;
		std::shared_ptr<Texture2D> m_spTexture;
		int m_size;
	public:
		TextComponent(const std::shared_ptr<GameObject>& owner);
		TextComponent(
			const std::shared_ptr<GameObject>& owner,
			const SDL_Color& color,
			const std::string& text,
			const std::string& fontFilePath,
			const int& size = 36);
		void SetColor(const SDL_Color& color);
		void SetText(const std::string& text);
		void SetFont(const std::string& filePath, int size);
		void CreateTextureFromFont();

		~TextComponent() = default;
	};
}


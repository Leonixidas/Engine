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
		std::string m_FilePath;
		std::shared_ptr<Font> m_spFont;
		std::shared_ptr<SDL_Color> m_spColor;
		int m_FontSize;

	public:
		TextComponent(const std::shared_ptr<GameObject>& owner);
		TextComponent(
			const std::shared_ptr<GameObject>& owner,
			const SDL_Color& color,
			const std::string& text,
			const std::string& fontFilePath,
			const int& size = 24);
		void SetColor(const SDL_Color& color);
		void SetText(const std::string& text);
		void SetFont(const std::string& filePath);
		void SetSize(int size);
		void CreateTextureFromFont();

		~TextComponent() = default;
	};
}


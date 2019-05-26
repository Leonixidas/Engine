#include "MiniginPCH.h"
#include "Font.h"

TTF_Font* imp::Font::GetFont() const {
	return mFont;
}

imp::Font::Font(const std::string& fullPath, unsigned int size) : mFont(nullptr), mSize(size)
{
	mFont = TTF_OpenFont(fullPath.c_str(), size);
	if (mFont == nullptr) 
	{
		throw std::runtime_error(std::string("Failed to load font: ") + SDL_GetError());
	}
}

imp::Font::~Font()
{
	TTF_CloseFont(mFont);
}

#include "MiniginPCH.h"
#include "Texture2D.h"
#include <SDL.h>

imp::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(mTexture);
}

int imp::Texture2D::GetDimensionsFromTexture(int& w, int& h)
{
	return SDL_QueryTexture(mTexture, nullptr, nullptr, &w, &h);
}

SDL_Texture* imp::Texture2D::GetSDLTexture() const
{
	return mTexture;
}

imp::Texture2D::Texture2D(SDL_Texture* texture)
{
	mTexture = texture;
}

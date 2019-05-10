#include "MiniginPCH.h"
#include "Texture2D.h"
#include <SDL.h>

dae::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(mTexture);
}

int dae::Texture2D::GetDimensionsFromTexture(int& w, int& h)
{
	return SDL_QueryTexture(mTexture, nullptr, nullptr, &w, &h);
}

SDL_Texture* dae::Texture2D::GetSDLTexture() const
{
	return mTexture;
}

dae::Texture2D::Texture2D(SDL_Texture* texture)
{
	mTexture = texture;
}

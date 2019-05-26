#pragma once
#include "SDL_keycode.h"

namespace imp
{
	class Observer
	{
	public:
		Observer() = default;
		virtual ~Observer() = default;
		virtual void OnNotify(WORD ) {}
		virtual void OnNotify(SDL_Keycode ) {}
	};
}


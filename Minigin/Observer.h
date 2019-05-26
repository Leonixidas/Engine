#pragma once

namespace imp
{
	class Observer
	{
	public:
		Observer() = default;
		virtual ~Observer() = default;
		virtual void OnNotify(WORD controllerButton) {}
		virtual void OnNotify(SDL_Keycode keyboardButton) {}
	};
}


#pragma once
#include <SDL_keycode.h>

namespace imp
{
	class Observer;

	class Subject
	{
	public:
		Subject() = default;
		~Subject() = default;
		void AddObserver(std::shared_ptr<Observer>& observer);
		void RemoveObserver(std::shared_ptr<Observer>& observer);
		void Notify(WORD controllerButton);
		void Notify(SDL_Keycode keyboardButton);
	private:
		std::vector<std::shared_ptr<Observer>> m_Observers;
	};
}


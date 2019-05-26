#include "MiniginPCH.h"
#include "Observer.h"
#include "Subject.h"

void imp::Subject::AddObserver(std::shared_ptr<Observer>& observer)
{
	m_Observers.push_back(observer);
}

void imp::Subject::RemoveObserver(std::shared_ptr<Observer>& observer)
{
	m_Observers.erase(std::find(m_Observers.begin(), m_Observers.end(), observer));
}

void imp::Subject::Notify(WORD controllerButton)
{
	for (auto obs : m_Observers)
	{
		obs->OnNotify(controllerButton);
	}
}

void imp::Subject::Notify(SDL_Keycode keyboardButton)
{
	for (auto obs : m_Observers)
	{
		obs->OnNotify(keyboardButton);
	}
}
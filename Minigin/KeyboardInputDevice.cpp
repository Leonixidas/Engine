#include "MiniginPCH.h"
#include "InputManager.h"
#include "KeyboardInputDevice.h"

imp::KeyboardInputComponent::KeyboardInputComponent()
{
}

void imp::KeyboardInputComponent::AddInputAction(const KeyBoardInputAction & action)
{
	m_InputActions.push_back(action);
	m_InputActions.back().SetID(unsigned int(m_InputActions.size() - 1));
}

void imp::KeyboardInputComponent::OnNotify(SDL_Keycode keyboardButton)
{
	for (auto action : m_InputActions)
	{
		if (action.GetTriggerButton() == keyboardButton)
		{
			action.GetCommand()->Execute();
		}
	}
}

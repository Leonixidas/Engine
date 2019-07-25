#include "MiniginPCH.h"
#include "InputManager.h"
#include "KeyboardInputDevice.h"

imp::KeyboardInputDevice::KeyboardInputDevice()
{
}

void imp::KeyboardInputDevice::AddInputAction(const KeyBoardInputAction & action)
{
	m_InputActions.push_back(action);
	m_InputActions.back().SetID(unsigned int(m_InputActions.size() - 1));
}

void imp::KeyboardInputDevice::Update()
{
	for (auto action : m_InputActions)
	{
		if (InputManager::GetInstance().IsPressed(action.GetTriggerButton()))
		{
			action.GetCommand()->Execute(action.GetGameObject());
		}
	}
}
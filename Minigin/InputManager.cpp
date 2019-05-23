#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>


bool dae::InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			return false;
		}
	}


	for (DWORD i = 0; i < XUSER_MAX_COUNT; ++i)
	{
		ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
		if (XInputGetState(i, &m_CurrentState) == ERROR_DEVICE_NOT_CONNECTED) continue;

		for (InputAction& action : m_InputActions)
		{
			if (IsPressed(action.GetTriggerButton()))
			{
				action.GetCommand()->Execute(action.GetAffected());
			}
		}
	}
	
	return true;
}

bool dae::InputManager::IsPressed(ControllerButton button) const
{
	return (m_CurrentState.Gamepad.wButtons & int(button)) != 0;
}


#include "MiniginPCH.h"
#include "InputManager.h"
#include "ControllerInputComponent.h"
#include <SDL.h>


bool imp::InputManager::ProcessInput()
{
	m_KeyPresses.clear();

	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			return false;
		}

		if (e.type == SDL_KEYDOWN)
		{
			m_KeyPresses.push_back(e.key.keysym.sym);
		}
	}


	for (DWORD i = 0; i < XUSER_MAX_COUNT; ++i)
	{
		if (!m_InputStates.empty())
		{
			ZeroMemory(&m_InputStates[i], sizeof(XINPUT_STATE));
			if (XInputGetState(i, &m_InputStates[i]) == ERROR_DEVICE_NOT_CONNECTED) continue;
		}
	}
	
	return true;
}

bool imp::InputManager::IsPressed(ControllerButton button, unsigned int controllerID) const
{
	if(!m_InputStates.empty())
		return (m_InputStates[controllerID].Gamepad.wButtons & int(button)) != 0;
	
	return false;
}

bool imp::InputManager::IsPressed(SDL_Keycode keycode) const
{
	return std::find(m_KeyPresses.begin(), m_KeyPresses.end(), keycode) != m_KeyPresses.end();
}



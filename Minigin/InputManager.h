#pragma once
#include <SDL_keycode.h>
#include "Singleton.h"
#include "Structs.h"
#include "KeyboardInputDevice.h"

namespace imp
{
	class GameObject;
	class Command;

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		bool IsPressed(ControllerButton button, unsigned int controllerID) const;
		bool IsPressed(SDL_Keycode keycode) const;

	private:
		std::vector<XINPUT_STATE> m_InputStates;
		std::vector<SDL_Keycode> m_KeyPresses;
	};

}

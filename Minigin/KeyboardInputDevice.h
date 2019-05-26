#pragma once
#include "InputDevice.h"
#include "Structs.h"

namespace imp
{
	class GameObject;

	class KeyboardInputComponent final : public InputDevice
	{
	public:
		KeyboardInputComponent();
		~KeyboardInputComponent() = default;

		void AddInputAction(const KeyBoardInputAction& action);
		virtual void OnNotify(SDL_Keycode keyboardButton) override;

	private:
		std::vector<KeyBoardInputAction> m_InputActions;
	};
}


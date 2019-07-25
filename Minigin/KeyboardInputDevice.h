#pragma once
#include "InputDevice.h"
#include "Structs.h"

namespace imp
{
	class GameObject;

	class KeyboardInputDevice final : public InputDevice
	{
	public:
		KeyboardInputDevice();
		~KeyboardInputDevice() = default;

		void AddInputAction(const KeyBoardInputAction& action);
		void Update();

	private:
		std::vector<KeyBoardInputAction> m_InputActions;
	};
}


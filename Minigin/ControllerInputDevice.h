#pragma once
#include "InputDevice.h"
#include "Structs.h"

namespace imp
{
	class GameObject;

	class ControllerInputDevice final : public InputDevice
	{
	public:
		ControllerInputDevice();
		~ControllerInputDevice();

		void AddInputAction(const ControllerInputAction& action);
		unsigned int GetControllerID() { return m_ControllerID; }
		void Update();
		
	private:
		static unsigned int m_ControllerCounter;
		unsigned int m_ControllerID;

		std::vector<ControllerInputAction> m_InputActions;
	};
}


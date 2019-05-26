#pragma once
#include <XInput.h>
#include "Observer.h"

namespace imp
{
	class InputDevice : public Observer
	{
	public:
		InputDevice() = default;
		~InputDevice() = default;
	};
}


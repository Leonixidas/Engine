#pragma once
#include <XInput.h>

namespace dae
{
	enum class ControllerButton
	{
		ArrowUp = XINPUT_GAMEPAD_DPAD_UP,
		ArrowDown = XINPUT_GAMEPAD_DPAD_DOWN,
		ArrowLeft = XINPUT_GAMEPAD_DPAD_LEFT,
		ArrowRight = XINPUT_GAMEPAD_DPAD_RIGHT,
		ButtonStart = XINPUT_GAMEPAD_START,
		ButtonBack = XINPUT_GAMEPAD_BACK,
		LeftShoulder = XINPUT_GAMEPAD_LEFT_SHOULDER,
		RightShoulder = XINPUT_GAMEPAD_RIGHT_SHOULDER,
		ButtonA = XINPUT_GAMEPAD_A,
		ButtonB = XINPUT_GAMEPAD_B,
		ButtonX = XINPUT_GAMEPAD_X,
		ButtonY = XINPUT_GAMEPAD_Y
	};
}
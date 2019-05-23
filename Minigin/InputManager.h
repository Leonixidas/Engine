#pragma once
#include <XInput.h>
#include "Singleton.h"
#include "Command.h"

namespace dae
{
	class GameObject;

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

	struct InputAction
	{
		InputAction(const std::shared_ptr<Command>& command, ControllerButton inputKey, const std::shared_ptr<GameObject>& affected)
			: m_Command(command)
			, m_TriggerButton(inputKey)
			, m_Affected(affected)
			, m_ID()
		{}

		ControllerButton GetTriggerButton() { return m_TriggerButton; }
		std::shared_ptr<Command>& GetCommand() { return m_Command; }
		std::shared_ptr<GameObject>& GetAffected() { return m_Affected; }
		unsigned int GetID() { return m_ID; }
		void SetID(const unsigned int id) { m_ID = id; }

	private:
		std::shared_ptr<Command> m_Command;
		ControllerButton m_TriggerButton;
		std::shared_ptr<GameObject> m_Affected;
		unsigned int m_ID;
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		bool IsPressed(ControllerButton button) const;
		void AddInputAction(const InputAction& inputAction) { m_InputActions.push_back(inputAction); }
	private:
		XINPUT_STATE m_CurrentState{};
		std::vector<InputAction> m_InputActions;
	};

}

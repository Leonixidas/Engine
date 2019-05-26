#pragma once
#include <SDL_keycode.h>
#include "Enums.h"
#include "Command.h"

namespace imp
{

	struct KeyBoardInputAction
	{
		KeyBoardInputAction(const std::shared_ptr<Command>& command, SDL_Keycode inputKey)
			: m_Command(command)
			, m_TriggerButton(inputKey)
			, m_ID()
		{
		}

		SDL_Keycode GetTriggerButton() { return m_TriggerButton; }
		std::shared_ptr<Command>& GetCommand() { return m_Command; }
		unsigned int GetID() { return m_ID; }
		void SetID(const unsigned int id) { m_ID = id; }

	private:
		std::shared_ptr<Command> m_Command;
		SDL_Keycode m_TriggerButton;
		unsigned int m_ID;
	};

	struct ControllerInputAction
	{
		ControllerInputAction(const std::shared_ptr<Command>& command, ControllerButton inputKey)
			: m_Command(command)
			, m_TriggerButton(inputKey)
			, m_ID()
		{
		}

		ControllerButton GetTriggerButton() { return m_TriggerButton; }
		std::shared_ptr<Command>& GetCommand() { return m_Command; }
		unsigned int GetID() { return m_ID; }
		void SetID(const unsigned int id) { m_ID = id; }

	private:
		std::shared_ptr<Command> m_Command;
		ControllerButton m_TriggerButton;
		unsigned int m_ID;
	};
}
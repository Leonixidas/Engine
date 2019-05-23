#pragma once
#include <XInput.h>
#include "BaseComponent.h"
#include "Command.h"

namespace dae
{
	class InputComponent :	public BaseComponent
	{
	public:
		explicit InputComponent(const std::shared_ptr<GameObject>& owner);
		~InputComponent();
		unsigned int GetPlayerID() { return m_PlayerID; }

	protected:
		static unsigned int m_PlayerCount;
		unsigned int m_PlayerID;
	};
}


#include "MiniginPCH.h"
#include "ControllerInputDevice.h"
#include "InputManager.h"
#include "GameObject.h"

unsigned int imp::ControllerInputDevice::m_ControllerCounter = 0;

imp::ControllerInputDevice::ControllerInputDevice()
{
	m_ControllerID = m_ControllerCounter;
	++m_ControllerCounter;
}

void imp::ControllerInputDevice::AddInputAction(const ControllerInputAction & action)
{
	m_InputActions.push_back(action);
	m_InputActions.back().SetID(unsigned int(m_InputActions.size() - 1));
}

void imp::ControllerInputDevice::OnNotify(WORD controllerButton)
{
	for (auto action : m_InputActions)
	{
		if (int(action.GetTriggerButton()) & controllerButton != 0)
		{
			action.GetCommand()->Execute();
		}
	}
}

imp::ControllerInputDevice::~ControllerInputDevice()
{
	--m_ControllerCounter;
}

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

void imp::ControllerInputDevice::Update()
{
	for (auto action : m_InputActions)
	{
		if ((InputManager::GetInstance().IsPressed(action.GetTriggerButton(), m_ControllerID)))
		{
			action.GetCommand()->Execute(action.GetGameObject());
		}
	}
}

imp::ControllerInputDevice::~ControllerInputDevice()
{
	--m_ControllerCounter;
}

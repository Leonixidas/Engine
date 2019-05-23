#include "MiniginPCH.h"
#include "ControllerInputComponent.h"
#include "InputManager.h"
#include "GameObject.h"

unsigned int dae::ControllerInputComponent::m_ControllerCounter = 0;

dae::ControllerInputComponent::ControllerInputComponent(const std::shared_ptr<GameObject>& owner)
	: InputComponent(owner)
{
	m_ControllerID = m_ControllerCounter;
	++m_ControllerCounter;
}

void dae::ControllerInputComponent::AddInputAction(const ControllerInputAction & action)
{
	m_InputActions.push_back(action);
	m_InputActions.back().SetID(unsigned int(m_InputActions.size() - 1));
}

void dae::ControllerInputComponent::Update()
{
	for (ControllerInputAction& action : m_InputActions)
	{
		if (InputManager::GetInstance().IsPressed(action.GetTriggerButton(), action.GetID()))
		{
			action.GetCommand()->Execute(m_pGameObject);
		}
	}
}


dae::ControllerInputComponent::~ControllerInputComponent()
{
	--m_ControllerCounter;
}

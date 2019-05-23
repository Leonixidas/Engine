#include "MiniginPCH.h"
#include "InputManager.h"
#include "KeyboardInputComponent.h"

dae::KeyboardInputComponent::KeyboardInputComponent(const std::shared_ptr<GameObject>& owner)
	: InputComponent(owner)
{
}

void dae::KeyboardInputComponent::AddInputAction(const KeyBoardInputAction & action)
{
	m_InputActions.push_back(action);
	m_InputActions.back().SetID(unsigned int(m_InputActions.size() - 1));
}

void dae::KeyboardInputComponent::Update()
{
	for (KeyBoardInputAction& action : m_InputActions)
	{
		if (InputManager::GetInstance().IsPressed(action.GetTriggerButton()))
		{
			action.GetCommand()->Execute(m_pGameObject);
		}
	}
}

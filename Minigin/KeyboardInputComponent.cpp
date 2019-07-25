#include "MiniginPCH.h"
#include "KeyboardInputComponent.h"


imp::KeyboardInputComponent::KeyboardInputComponent(const std::shared_ptr<GameObject>& owner)
	:BaseComponent(owner)
{
}

void imp::KeyboardInputComponent::AddInputAction(const KeyboardInputAction & action)
{
	auto iter = std::find_if(m_KeyboardActions.begin(), m_KeyboardActions.end(), [&action](const KeyboardInputAction& a) 
	{
		return a.GetTriggerButton() == action.GetTriggerButton();
	});

	if (iter == m_KeyboardActions.end()) m_KeyboardActions.push_back(action);
	else std::cout << "There already exists an action for this key\n";
}

void imp::KeyboardInputComponent::RemoveInputAction(const SDL_Keycode & key)
{
	auto iter = std::find_if(m_KeyboardActions.begin(), m_KeyboardActions.end(), [&key](const KeyboardInputAction& a)
	{
		return a.GetTriggerButton() == key;
	});

	if (iter != m_KeyboardActions.end()) m_KeyboardActions.erase(iter);
	else std::cout << "no input action with this key\n";
}


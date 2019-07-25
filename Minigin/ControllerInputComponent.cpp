#include "MiniginPCH.h"
#include "ControllerInputComponent.h"

unsigned int imp::ControllerInputComponent::m_ControllerCount = 0;

imp::ControllerInputComponent::ControllerInputComponent(const std::shared_ptr<GameObject>& owner)
	:BaseComponent(owner)
{
	m_ControllerID = m_ControllerCount;
	++m_ControllerCount;
}

imp::ControllerInputComponent::~ControllerInputComponent()
{
	--m_ControllerCount;
}

void imp::ControllerInputComponent::AddInputAction(const ControllerInputAction& action)
{
	auto iter = std::find_if(m_ControllerActions.begin(), m_ControllerActions.end(), [&action](const ControllerInputAction& a)
	{
		return a.GetTriggerButton() == action.GetTriggerButton();
	});

	if (iter == m_ControllerActions.end()) m_ControllerActions.push_back(action);
	else std::cout << "There already exists an action for this button\n";
}

void imp::ControllerInputComponent::RemoveInputAction(const ControllerButton & button)
{
	auto iter = std::find_if(m_ControllerActions.begin(), m_ControllerActions.end(), [&button](const ControllerInputAction& a)
	{
		return button == a.GetTriggerButton();
	});

	if (iter != m_ControllerActions.end()) m_ControllerActions.erase(iter);
	else std::cout << "no input action with this button\n";
}

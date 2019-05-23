#include "MiniginPCH.h"
#include "InputComponent.h"

unsigned int dae::InputComponent::m_PlayerCount = 0;

dae::InputComponent::InputComponent(const std::shared_ptr<GameObject>& owner)
	:BaseComponent(owner)
{
	m_PlayerID = m_PlayerCount;
	++m_PlayerCount;
}

dae::InputComponent::~InputComponent()
{
	--m_PlayerCount;
}

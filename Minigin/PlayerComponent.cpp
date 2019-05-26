#include "MiniginPCH.h"
#include "PlayerComponent.h"


unsigned int imp::PlayerComponent::m_PlayerCount = 0;

imp::PlayerComponent::PlayerComponent(const std::shared_ptr<GameObject>& owner)
	:BaseComponent(owner)
{
	m_PlayerID = m_PlayerCount;
	++m_PlayerCount;
}

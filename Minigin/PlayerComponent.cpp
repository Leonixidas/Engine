#include "MiniginPCH.h"
#include "PlayerComponent.h"


unsigned int imp::PlayerComponent::m_PlayerCount = 0;

imp::PlayerComponent::PlayerComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
	, m_PlayerState(PlayerState::IDLE)
	, m_PlayerDirection(Direction::FACE_RIGHT)
	, m_PreviousPlayerState(PlayerState::IDLE)
	, m_PreviousPlayerDirection(Direction::FACE_RIGHT)
{
	m_PlayerID = m_PlayerCount;
	++m_PlayerCount;
}

void imp::PlayerComponent::Update()
{
}

void imp::PlayerComponent::SetPlayerState(PlayerState playerState)
{
	m_PreviousPlayerState = m_PlayerState;
	m_PlayerState = playerState;
}

void imp::PlayerComponent::SetPlayerDirection(Direction dir)
{
	m_PreviousPlayerDirection = m_PlayerDirection;
	m_PlayerDirection = dir;
}

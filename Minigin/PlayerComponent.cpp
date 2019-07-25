#include "MiniginPCH.h"
#include "PlayerComponent.h"
#include "ControllerInputDevice.h"
#include "KeyboardInputDevice.h"


unsigned int imp::PlayerComponent::m_PlayerCount = 0;

imp::PlayerComponent::PlayerComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
	, m_ControllerDevice(std::shared_ptr<ControllerInputDevice>(new ControllerInputDevice()))
	, m_KeyBoardDevice(std::shared_ptr<KeyboardInputDevice>(new KeyboardInputDevice()))
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
	m_ControllerDevice->Update();
	m_KeyBoardDevice->Update();
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

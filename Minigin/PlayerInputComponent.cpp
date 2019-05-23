#include "MiniginPCH.h"
#include "PlayerInputComponent.h"
#include "InputManager.h"
#include "GameObject.h"

unsigned int dae::PlayerInputComponent::m_Counter = 0;

dae::PlayerInputComponent::PlayerInputComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
{
	m_PlayerID = m_Counter;
	++m_Counter;
}

void dae::PlayerInputComponent::AddInputAction(const InputAction & action)
{
	m_InputActions.push_back(action);
	m_InputActions.back().SetID(unsigned int(m_InputActions.size() - 1));
}

void dae::PlayerInputComponent::Update()
{
	for (InputAction& action : m_InputActions)
	{

	}
}


dae::PlayerInputComponent::~PlayerInputComponent()
{
}

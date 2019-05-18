#include "MiniginPCH.h"
#include "AnimatorComponent.h"
#include "GameObject.h"
#include "TextureComponent.h"


dae::AnimatorComponent::AnimatorComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
	, m_AnimationSpeed(0.1f)
	, m_AnimationTimer()
	, m_ColumSize()
	, m_RowSize()
	, m_Colums()
	, m_Rows()
	, m_AnimationClip()
	, m_AnimationNumber()
	, m_CurrentAnimation()
{
}

void dae::AnimatorComponent::Update(float elapsedSec)
{
	m_AnimationTimer += elapsedSec;
	
	if (m_AnimationTimer > m_AnimationSpeed)
	{
		++m_CurrentAnimation %= m_AnimationNumber;
		HandleAnimation();
	}
}

void dae::AnimatorComponent::SetSpriteGrid(int rows, int colums, float rowSize, float columSize)
{
	m_Rows = rows;
	m_Colums = colums;
	m_RowSize = rowSize;
	m_ColumSize = columSize;
}

void dae::AnimatorComponent::SetAnimationSpeed(float animationSpeed)
{
	m_AnimationSpeed = animationSpeed;
}

void dae::AnimatorComponent::SetAnimationNumber(int animationNumber)
{
	m_AnimationNumber = animationNumber;
}

void dae::AnimatorComponent::HandleAnimation()
{
	TextureComponent texComp = m_pGameObject->GetComponent<TextureComponent>();

	glm::vec2 pos{};
	pos.x = m_ColumSize * (m_CurrentAnimation % m_Colums);
	pos.y = m_RowSize * (m_CurrentAnimation / m_Colums);
	texComp.SetDestRect()
}

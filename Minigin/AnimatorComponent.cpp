#include "MiniginPCH.h"
#include "AnimatorComponent.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "Transform.h"
#include "GameTime.h"


dae::AnimatorComponent::AnimatorComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
	, m_AnimationSpeed(0.1f)
	, m_AnimationTimer()
	, m_ClipWidth()
	, m_ClipHeight()
	, m_Colums()
	, m_Rows()
	, m_AnimationClip()
	, m_AnimationNumber()
	, m_CurrentAnimation()
{
}

void dae::AnimatorComponent::Update()
{
	m_AnimationTimer += GameTime::GetInstance().GetElapsedSec();
	
	if (m_AnimationTimer > m_AnimationSpeed)
	{
		++m_CurrentAnimation %= m_AnimationNumber;
		HandleAnimation();
	}
}

void dae::AnimatorComponent::SetSpriteGrid(int rows, int colums)
{
	m_Rows = rows;
	m_Colums = colums;

	TextureComponent *tex = m_pGameObject->GetComponent<TextureComponent>();
	glm::vec2 texDim = tex->GetTextureSizes();

	m_ClipWidth = texDim.x / m_Colums;
	m_ClipHeight = texDim.y / m_Rows;
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
	TextureComponent *texComp = m_pGameObject->GetComponent<TextureComponent>();
	if (texComp == nullptr) return;
	glm::vec2 pos{};
	glm::vec3 ownerPos{ m_pGameObject->GetTransform().GetPosition() };

	pos.x = m_SourceStartPos.x + m_ClipWidth * (m_CurrentAnimation % m_Colums);
	pos.y = m_SourceStartPos.y + m_ClipHeight * (m_CurrentAnimation / m_Colums);

	texComp->SetSourceRect(pos, m_ClipWidth, m_ClipHeight);
	texComp->SetDestRect({ ownerPos.x, ownerPos.y }, m_ClipWidth, m_ClipHeight);
}

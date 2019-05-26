#include "MiniginPCH.h"
#include <algorithm>
#include "AnimatorComponent.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "PlayerComponent.h"
#include "Transform.h"
#include "GameTime.h"


imp::AnimatorComponent::AnimatorComponent(const std::shared_ptr<GameObject>& owner)
	: BaseComponent(owner)
	, m_AnimationTimer()
	, m_CurrentFrame()
{
}

void imp::AnimatorComponent::Update()
{
	HandleAnimation();
}

void imp::AnimatorComponent::HandleAnimation()
{
	auto texComp = m_pGameObject->GetComponent<TextureComponent>();
	auto player = m_pGameObject->GetComponent<PlayerComponent>();
	float elapsedSec = GameTime::GetInstance().GetElapsedSec();
	
	if (player != nullptr)
	{
		PlayerState state = player->GetPlayerState();
		if (m_CurrentAnimClip != nullptr)
		{
			if (int(state) != m_CurrentAnimClip->GetPlayerState())
			{
				auto it = std::find_if(m_AnimationClips.begin(), m_AnimationClips.end(), [state](std::shared_ptr<AnimationClip>& clip) { return clip->GetPlayerState() == int(state); });

				if (it != m_AnimationClips.end())
				{
					m_CurrentAnimClip = (*it);
				}
				
				m_CurrentFrame = 0;
				m_AnimationTimer = 0.f;
				glm::vec3 pos = m_pGameObject->GetTransform().GetPosition();
				glm::vec2 texPos = m_CurrentAnimClip->GetTexturePosition();
				glm::vec2 size = m_CurrentAnimClip->GetFrameSize();
				texComp->SetSourceRect(texPos, size.x, size.y);
				
				texComp->SetDestRect({ pos.x,pos.y }, size.x, size.y);
			}
		}
		else
		{
			auto it = std::find_if(m_AnimationClips.begin(), m_AnimationClips.end(), [state](std::shared_ptr<AnimationClip>& clip) { return clip->GetPlayerState() == int(state); });
			
			if (it != m_AnimationClips.end())
			{
				m_CurrentAnimClip = (*it);
			}

			m_CurrentFrame = 0;
			m_AnimationTimer = 0.f;
			glm::vec3 pos = m_pGameObject->GetTransform().GetPosition();
			glm::vec2 texPos = m_CurrentAnimClip->GetTexturePosition();
			glm::vec2 size = m_CurrentAnimClip->GetFrameSize();
			texComp->SetSourceRect(texPos, size.x, size.y);
			texComp->SetDestRect({ pos.x,pos.y }, size.x, size.y);
		}
	}

	if (m_CurrentAnimClip->GetFrameAmount() > 1)
	{
		m_AnimationTimer += m_CurrentAnimClip->GetAnimationSpeed() * elapsedSec;

		if (m_AnimationTimer > m_CurrentAnimClip->GetFrameTime())
		{
			m_AnimationTimer = 0.0f;
			++m_CurrentFrame;
			m_CurrentFrame %= m_CurrentAnimClip->GetFrameAmount();
			glm::vec2 pos = m_CurrentAnimClip->GetTexturePosition();
			glm::vec2 size = m_CurrentAnimClip->GetFrameSize();
			pos.x = pos.x + m_CurrentFrame * size.x;
			texComp->SetSourceRect( pos, size.x, size.y );
		}
	}
}

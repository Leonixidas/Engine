#pragma once
#include "BaseComponent.h"
#include "Structs.h"

namespace imp
{
	//TODO make a system that uses conditions to switch animations
	//Ref Gameplay Programming && UNITY
	//or use trigger states of the input to change the animation
	//Observer will come in handy for this
	class AnimatorComponent final : public BaseComponent
	{
	public:
		AnimatorComponent(const std::shared_ptr<GameObject>& owner);
		~AnimatorComponent() = default;

		virtual void Update();

		void AddAnimationClip(const std::shared_ptr<AnimationClip>& animClip)
		{
			m_AnimationClips.push_back(animClip);
		}

	private:
		void HandleAnimation();

		std::vector<std::shared_ptr<AnimationClip>> m_AnimationClips;
		std::shared_ptr<AnimationClip> m_CurrentAnimClip;
		float m_AnimationTimer;
		int m_CurrentFrame;
	};
}


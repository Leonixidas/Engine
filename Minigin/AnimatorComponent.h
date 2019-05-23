#pragma once
#include "BaseComponent.h"

namespace dae
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
		void SetSpriteGrid(int rows, int colums);

		//This is the speed for how fast the next animations clip is shown
		//so after this value has been reached the next animation clip will be shown
		void SetAnimationSpeed(float animationSpeed);

		//Animation number is the amount of sprites the texture has
		//This is to prevent animation sheets with blank space to still have animations 
		//without a frame where it doesn't show the sprite
		void SetAnimationNumber(int animationNumber);


	private:
		void HandleAnimation();

		float m_ClipHeight;
		float m_ClipWidth;
		float m_AnimationSpeed;
		float m_AnimationTimer;

		int m_Rows;
		int m_Colums;
		int m_AnimationClip;
		int m_AnimationNumber;
		int m_CurrentAnimation;

	};
}


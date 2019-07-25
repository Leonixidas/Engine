#pragma once
#include <SDL_keycode.h>
#include "Enums.h"
#include "Command.h"

namespace imp
{

	struct KeyBoardInputAction
	{
		KeyBoardInputAction(const std::shared_ptr<Command>& command, SDL_Keycode inputKey, const std::shared_ptr<GameObject>& object)
			: m_Command(command)
			, m_GameObject(object)
			, m_TriggerButton(inputKey)
			, m_ID()
		{
		}

		SDL_Keycode GetTriggerButton() { return m_TriggerButton; }
		std::shared_ptr<Command>& GetCommand() { return m_Command; }
		std::shared_ptr<GameObject>& GetGameObject() { return m_GameObject; }
		unsigned int GetID() { return m_ID; }
		void SetID(const unsigned int id) { m_ID = id; }

	private:
		std::shared_ptr<Command> m_Command;
		std::shared_ptr<GameObject> m_GameObject;
		SDL_Keycode m_TriggerButton;
		unsigned int m_ID;
	};

	struct ControllerInputAction
	{
		ControllerInputAction(const std::shared_ptr<Command>& command, ControllerButton inputKey, const std::shared_ptr<GameObject>& object)
			: m_Command(command)
			, m_GameObject(object)
			, m_TriggerButton(inputKey)
			, m_ID()
		{
		}

		ControllerButton GetTriggerButton() { return m_TriggerButton; }
		std::shared_ptr<Command>& GetCommand() { return m_Command; }
		std::shared_ptr<GameObject>& GetGameObject() { return m_GameObject; }
		unsigned int GetID() { return m_ID; }
		void SetID(const unsigned int id) { m_ID = id; }

	private:
		std::shared_ptr<Command> m_Command;
		std::shared_ptr<GameObject> m_GameObject;
		ControllerButton m_TriggerButton;
		unsigned int m_ID;
	};

	struct AnimationClip
	{
		AnimationClip(int state, int dir, int frameAmount, glm::vec2 frameSize, float frameTime, float animationSpeed, glm::vec2 posTexture)
			: m_PosTexture(posTexture)
			, m_FrameTime(frameTime)
			, m_AnimationSpeed(animationSpeed)
			, m_FrameSize(frameSize)
			, m_Playerstate(state)
			, m_PlayerDirection(dir)
			, m_FrameAmount(frameAmount)
		{
		}

		~AnimationClip() = default;

		glm::vec2 GetTexturePosition() { return m_PosTexture; }
		glm::vec2 GetFrameSize() { return m_FrameSize; }

		float GetAnimationSpeed() { return m_AnimationSpeed; }
		float GetFrameTime() { return m_FrameTime; }

		int GetPlayerState() { return m_Playerstate; }
		int GetPlayerDirection() { return m_PlayerDirection; }
		int GetFrameAmount() { return m_FrameAmount; }

	private:
		glm::vec2 m_PosTexture;
		glm::vec2 m_FrameSize;
		float m_FrameTime;
		float m_AnimationSpeed;
		int m_Playerstate;
		int m_PlayerDirection;
		int m_FrameAmount;
	};
}
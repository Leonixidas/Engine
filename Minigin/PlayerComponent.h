#pragma once
#include "BaseComponent.h"
#include "Enums.h"

namespace imp
{
	class GameObject;
	class KeyboardInputDevice;
	class ControllerInputDevice;

	class PlayerComponent : public BaseComponent
	{
	public:
		PlayerComponent(const std::shared_ptr<GameObject>& owner);
		~PlayerComponent() = default;

		virtual void Update() override;

		std::shared_ptr<ControllerInputDevice>& GetControllerInput() { return m_ControllerDevice; }
		std::shared_ptr<KeyboardInputDevice>& GetKeyboardInput() { return m_KeyBoardDevice; }

		PlayerState GetPlayerState() { return m_PlayerState; }
		Direction GetPlayerDirection() { return m_PlayerDirection; }
		Direction GetPreviousPlayerDirection() { return m_PreviousPlayerDirection; }

		void SetPlayerState(PlayerState playerState);
		void SetPlayerDirection(Direction dir);

	private:
		std::shared_ptr<ControllerInputDevice> m_ControllerDevice;
		std::shared_ptr<KeyboardInputDevice> m_KeyBoardDevice;
		static unsigned int m_PlayerCount;
		unsigned int  m_PlayerID;
		PlayerState m_PlayerState;
		Direction m_PlayerDirection;
		PlayerState m_PreviousPlayerState;
		Direction m_PreviousPlayerDirection;
	};
}


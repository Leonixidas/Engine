#pragma once
#include "BaseComponent.h"

namespace dae
{
	class Command;
	class GameObject;
	struct InputAction;

	class PlayerInputComponent final : public BaseComponent
	{
	public:
		PlayerInputComponent(const std::shared_ptr<GameObject>& owner);
		~PlayerInputComponent() = default;

		void AddInputAction(const InputAction& action);
		virtual void Update() override;
		
	private:
		static unsigned int m_Counter;
		unsigned int m_PlayerID;

		std::vector<InputAction> m_InputActions;
	};
}


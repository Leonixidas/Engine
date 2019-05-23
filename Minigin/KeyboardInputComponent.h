#pragma once
#include "InputComponent.h"
#include "Structs.h"

namespace dae
{
	class GameObject;
	class Command;

	

	class KeyboardInputComponent final : public InputComponent
	{
	public:
		KeyboardInputComponent(const std::shared_ptr<GameObject>& owner);
		~KeyboardInputComponent() = default;

		void AddInputAction(const KeyBoardInputAction& action);
		void Update() override;

	private:
		std::vector<KeyBoardInputAction> m_InputActions;
	};
}


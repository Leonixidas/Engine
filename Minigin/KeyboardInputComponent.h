#pragma once
#include "BaseComponent.h"
#include "Structs.h"

namespace imp
{
	class KeyboardInputComponent :	public BaseComponent
	{
	public:
		KeyboardInputComponent(const std::shared_ptr<GameObject>& owner);
		~KeyboardInputComponent() = default;

		void AddInputAction(const KeyboardInputAction& action);
		void RemoveInputAction(const SDL_Keycode& key);

	private:
		std::vector<KeyboardInputAction> m_KeyboardActions{};
	};
}


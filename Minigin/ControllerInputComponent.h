#pragma once
#include "InputComponent.h"
#include "Structs.h"

namespace dae
{
	class Command;
	class GameObject;

	class ControllerInputComponent final : public InputComponent
	{
	public:
		ControllerInputComponent(const std::shared_ptr<GameObject>& owner);
		~ControllerInputComponent();

		void AddInputAction(const ControllerInputAction& action);
		virtual void Update() override;
		unsigned int GetControllerID() { return m_ControllerID; }
		
	private:
		static unsigned int m_ControllerCounter;
		unsigned int m_ControllerID;

		std::vector<ControllerInputAction> m_InputActions;
	};
}


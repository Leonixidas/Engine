#pragma once
#include "BaseComponent.h"
#include "Structs.h"

namespace imp
{
	class ControllerInputComponent final : public BaseComponent
	{
	public:
		ControllerInputComponent(const std::shared_ptr<GameObject>& owner);
		~ControllerInputComponent();

		void AddInputAction(const ControllerInputAction& action);
		void RemoveInputAction(const ControllerButton& button);

	private:
		std::vector<ControllerInputAction> m_ControllerActions{};
		static unsigned int m_ControllerCount;
		int m_ControllerID;
	};
}



#pragma once
#include "BaseComponent.h"

namespace imp
{
	class GameObject;
	class InputDevice;

	class PlayerComponent : public BaseComponent
	{
	public:
		PlayerComponent(const std::shared_ptr<GameObject>& owner, bool useController);
		~PlayerComponent() = default;

	private:


		static unsigned int m_PlayerCount;
		unsigned int  m_PlayerID;
	};
}


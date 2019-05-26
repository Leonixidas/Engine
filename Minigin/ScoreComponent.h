#pragma once
#include "BaseComponent.h"
namespace imp
{
	class ScoreComponent final :	public BaseComponent
	{
	public:
		ScoreComponent(const std::shared_ptr<GameObject>& owner);
		~ScoreComponent();
	};
}


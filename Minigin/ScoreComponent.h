#pragma once
#include "BaseComponent.h"
#include "Observer.h"
namespace imp
{
	class ScoreComponent final :public BaseComponent, Observer
	{
	public:
		ScoreComponent(const std::shared_ptr<GameObject>& owner);
		~ScoreComponent();
	};
}


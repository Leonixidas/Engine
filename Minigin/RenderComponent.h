#pragma once
#include "BaseComponent.h"
namespace dae
{
	class GameObject;

	class RenderComponent : public BaseComponent
	{
	public:
		RenderComponent(const std::shared_ptr<GameObject>& owner);
		~RenderComponent() = default;
		virtual void Render() const override;
	};
}


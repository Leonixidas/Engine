#pragma once
#include "BaseComponent.h"
namespace imp
{
	class GameObject;
	class Renderer;

	class RenderComponent final : public BaseComponent
	{
	public:
		RenderComponent(const std::shared_ptr<GameObject>& owner);
		~RenderComponent() = default;
		virtual void Render() const;
	};
}


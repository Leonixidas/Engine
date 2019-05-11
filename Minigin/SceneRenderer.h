#pragma once
#include "Singleton.h"
#include "RenderComponent.h"

namespace dae
{
	class SceneRenderer final
	{
	public:
		virtual ~SceneRenderer() = default;
		SceneRenderer() = default;
		void AddRenderComponent(const RenderComponent& component);
		void Render() const;
	private:
		std::vector<RenderComponent> m_RenderComponents;
	};

}


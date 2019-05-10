#pragma once
#include "Singleton.h"
namespace dae
{
	class RenderComponent;

	class RenderManager final : public Singleton<RenderManager>
	{
	public:
		virtual ~RenderManager() = default;
	private:
		RenderManager();
		std::vector<RenderComponent>
	};

}


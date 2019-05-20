#include "MiniginPCH.h"
#include "SceneRenderer.h"

void dae::SceneRenderer::AddRenderComponent(const RenderComponent & component)
{
	m_RenderComponents.push_back(component);
}

void dae::SceneRenderer::Render() const
{
	for (size_t i{ 0 }, size{ m_RenderComponents.size() }; i < size; ++i)
	{
		m_RenderComponents[i].Render();
	}
}

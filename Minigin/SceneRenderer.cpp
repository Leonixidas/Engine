#include "MiniginPCH.h"
#include "SceneRenderer.h"

void imp::SceneRenderer::AddRenderComponent(const RenderComponent & component)
{
	m_RenderComponents.push_back(component);
}

void imp::SceneRenderer::Render() const
{
	for (size_t i{ 0 }, size{ m_RenderComponents.size() }; i < size; ++i)
	{
		m_RenderComponents[i].Render();
	}
}

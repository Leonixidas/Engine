#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Renderer.h"


void dae::SceneManager::Update(float elapsedSec)
{
	for(auto scene : m_Scenes)
	{
		scene->RootUpdate(elapsedSec);
	}
}

void dae::SceneManager::Render()
{
	if(m_ActiveScene != nullptr)
		m_ActiveScene->RootRender(); // only the active scene needs to render
}

void dae::SceneManager::RootInitialize()
{
	for (auto scene : m_Scenes)
	{
		scene->RootInitialize();
	}
}

void dae::SceneManager::SetActiveScene(const unsigned int id)
{
	if (id < m_Scenes.size())
	{
		m_ActiveScene = m_Scenes[id];
	}
}

dae::Scene& dae::SceneManager::GetActiveScene()
{
	return *m_ActiveScene;
}

void dae::SceneManager::AddScene(const std::shared_ptr<Scene>& scene)
{
	m_Scenes.push_back(scene);
}

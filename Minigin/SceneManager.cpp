#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Renderer.h"
#include <algorithm>


void imp::SceneManager::Update()
{
	if (m_ActiveScene != nullptr)
		m_ActiveScene->RootUpdate();
}

void imp::SceneManager::Render()
{
	if(m_ActiveScene != nullptr)
		m_ActiveScene->RootRender(); // only the active scene needs to render
}

void imp::SceneManager::RootInitialize()
{
	for (auto scene : m_Scenes)
	{
		scene->RootInitialize();
	}
}

void imp::SceneManager::SetActiveScene(const unsigned int id)
{
	if (id < m_Scenes.size())
	{
		m_PreviousScene = m_ActiveScene;
		m_ActiveScene = m_Scenes[id];
	}
}

void imp::SceneManager::SetActiveScene(const std::string & name)
{
	auto it = std::find_if(m_Scenes.begin(), m_Scenes.end(), [name](std::shared_ptr<Scene> scene) { return name.compare(scene->GetSceneName()) == 0; });

	if (it != m_Scenes.end())
		SetActiveScene((*it)->GetID());
}

void imp::SceneManager::GoToPreviousScene()
{
	auto temp = m_PreviousScene;
	m_PreviousScene = m_ActiveScene;
	m_ActiveScene = temp;
}

imp::Scene& imp::SceneManager::GetActiveScene()
{
	return *m_ActiveScene;
}

void imp::SceneManager::AddScene(const std::shared_ptr<Scene>& scene)
{
	m_Scenes.push_back(scene);
}

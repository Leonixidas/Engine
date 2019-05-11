#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include "SceneRenderer.h"

unsigned int dae::Scene::idCounter = 0;

dae::Scene::Scene(const std::string& name) 
	: m_Name(name)
	, m_SceneRenderer(std::make_unique<SceneRenderer>())
{ 
	m_ID = idCounter;
	++idCounter;
}

dae::Scene::~Scene()
{
	for (const auto& o : m_Objects)
	{
		o->~GameObject();
	}
}

void dae::Scene::Add(const std::shared_ptr<GameObject>& object)
{
	m_Objects.push_back(object);
}

void dae::Scene::Update(float elapsedSec)
{
	for(const auto& gameObject : m_Objects)
	{
		gameObject->Update(elapsedSec);
	}
}

void dae::Scene::RootUpdate(float elapsedSec)
{
	Update(elapsedSec);

	for (auto obj : m_Objects)
	{
		obj->Update(elapsedSec);
	}
}

void dae::Scene::Render() const
{
	m_SceneRenderer->Render();
}

dae::SceneRenderer & dae::Scene::GetSceneRenderer()
{
	return *m_SceneRenderer;
}



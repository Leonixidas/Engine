#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"

unsigned int dae::Scene::idCounter = 0;

dae::Scene::Scene(const std::string& name) : m_Name(name)
{ 
	m_ID = idCounter;
	++idCounter;
}

dae::Scene::~Scene()
{
	for (const auto& o : m_Objects)
	{
		o->~SceneObject();
	}
}

void dae::Scene::Add(const std::shared_ptr<SceneObject>& object)
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

void dae::Scene::Render() const
{
	for (const auto& gameObject : m_Objects)
	{
		gameObject->Render();
	}
}


#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "Renderer.h"
#include "SceneRenderer.h"
#include "TextComponent.h"
#include "TextureComponent.h"

unsigned int imp::Scene::idCounter = 0;


imp::Scene::Scene(const std::string& name, const std::shared_ptr<MiniginGame>& game)
	: m_Name(name)
	, m_pSceneRenderer(std::shared_ptr<SceneRenderer>(new SceneRenderer()))
	, m_pGame(game)
{ 
	m_ID = idCounter;
	++idCounter;
}

imp::Scene::~Scene()
{
	for (const auto& o : m_Objects)
	{
		o->~GameObject();
	}
}

void imp::Scene::AddGameObject(const std::shared_ptr<GameObject>& object)
{
	if (std::find(m_Objects.begin(), m_Objects.end(), object) == m_Objects.end())
	{
		m_Objects.push_back(object);
		if (object->HasComponent<TextureComponent>() || object->HasComponent<TextComponent>())
			m_pSceneRenderer->AddRenderComponent(std::move(RenderComponent(object)));
	}
	//TODO Log if object already exists
}

void imp::Scene::RootUpdate()
{
	Update();

	for (auto obj : m_Objects)
	{
		obj->Update();
	}
}

void imp::Scene::RootRender() const
{
	m_pSceneRenderer->Render();
}

void imp::Scene::RootInitialize()
{
	m_IsInitialized = true;
	Initialize();
}



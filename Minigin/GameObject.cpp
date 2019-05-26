#include "MiniginPCH.h"
#include "GameObject.h"
#include "BaseComponent.h"
#include "Transform.h"


imp::GameObject::GameObject()
	: m_Transform(std::shared_ptr<Transform>(new Transform()))
{
}

imp::GameObject::GameObject(const std::shared_ptr<GameObject>& parent)
	:m_Transform(std::shared_ptr<Transform>(new Transform()))
	,m_Parent(parent)
{
}

imp::GameObject::~GameObject()
{
	for (auto c : m_Components)
	{
		delete c;
		c = nullptr;
	}
}

void imp::GameObject::Update()
{
	for (auto c : m_Components)
	{
		c->Update();
	}

	for (auto o : m_Children)
	{
		o->Update();
	}
}

void imp::GameObject::AddComponent(BaseComponent* component)
{
	for (auto c : m_Components)
	{
		if (c == component)
			//TODO write something with the logger
			return;
	}
	m_Components.push_back(component);
}

void imp::GameObject::AddChild(const std::shared_ptr<GameObject>& child)
{
	if(std::find(m_Children.begin(), m_Children.end(), child) == m_Children.end())
		m_Children.push_back(child);
	//TODO send a message to the logger
}

void imp::GameObject::DeleteChild(const std::shared_ptr<GameObject>& child)
{
	auto found = std::find(m_Children.begin(), m_Children.end(), child);
	if (found != m_Children.end())
		m_Children.erase(found);
	//TODO send a message to the logger
}

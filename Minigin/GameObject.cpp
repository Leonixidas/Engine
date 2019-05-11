#include "MiniginPCH.h"
#include "GameObject.h"
#include "BaseComponent.h"
#include "Transform.h"


dae::GameObject::GameObject()
	: m_Transform(std::make_shared<Transform>())
{
}

dae::GameObject::~GameObject()
{
	for (auto c : m_Components)
	{
		delete c;
		c = nullptr;
	}
}

void dae::GameObject::Update(float elapsedSec)
{
	for (auto c : m_Components)
	{
		c->Update(elapsedSec);
	}

	for (auto o : m_Children)
	{
		o->Update(elapsedSec);
	}
}

void dae::GameObject::AddComponent(BaseComponent* component)
{
	for (auto c : m_Components)
	{
		if (c == component)
			//TODO write something with the logger
			return;
	}
	m_Components.push_back(component);
}

void dae::GameObject::AddChild(const std::shared_ptr<GameObject>& child)
{
	if(std::find(m_Children.begin(), m_Children.end(), child) == m_Children.end())
		m_Children.push_back(child);
	//TODO send a message to the logger
}

void dae::GameObject::DeleteChild(const std::shared_ptr<GameObject>& child)
{
	auto found = std::find(m_Children.begin(), m_Children.end(), child);
	if (found != m_Children.end())
		m_Children.erase(found);
	//TODO send a message to the logger
}

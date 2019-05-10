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

void dae::GameObject::Update(float )
{
}

void dae::GameObject::AddComponent(BaseComponent* component)
{
	m_Components.push_back(component);
}

void dae::GameObject::Render()const
{
	for (auto c : m_Components)
		c->Render();
}

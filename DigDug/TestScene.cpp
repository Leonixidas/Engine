#include "pch.h"
#include "TestScene.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "Transform.h"
#include "RenderComponent.h"
#include "SceneRenderer.h"
#include "TextComponent.h"

dae::TestScene::TestScene()
	: Scene(std::move("TestScene"))
{
}

void dae::TestScene::Initialize()
{
	auto obj = std::make_shared<GameObject>();
	TextureComponent* texComp = new TextureComponent(obj);
	texComp->SetTexture(std::move("background.jpg"));

	texComp->SetDestRect({ 0,0 }, 1280.f, 720.f);
	obj->AddComponent(texComp);

	GetSceneRenderer().AddRenderComponent(std::move(RenderComponent(obj)));
	AddGameObject(obj);

	obj = std::make_shared<GameObject>();
	texComp = new TextureComponent(obj);
	texComp->SetTexture(std::move("logo.png"));
	glm::vec2 texDim = texComp->GetTextureSizes();
	obj->AddComponent(texComp);
	obj->GetTransform().SetPosition( 1280.f / 2 - texDim.x / 2, 720.f / 2 - texDim.y / 2 ,0 );
	m_Logo = obj;
	GetSceneRenderer().AddRenderComponent(std::move(RenderComponent(obj)));
	AddGameObject(obj);

	obj = std::make_shared<GameObject>();
	texComp = new TextureComponent(obj);
	obj->AddComponent(texComp);
	TextComponent *textComp = new TextComponent(obj);
	textComp->SetFont(std::move("Lingua.otf"), 36);
	textComp->SetText(std::move(std::to_string(100)));
	textComp->SetColor({ 0,255,0,255 });
	obj->AddComponent(textComp);
	m_FPSText = obj;
	GetSceneRenderer().AddRenderComponent(std::move(RenderComponent(obj)));
	AddGameObject(obj);
	

}

void dae::TestScene::Update(float elapsedSec)
{
	TextComponent *text = m_FPSText->GetComponent<TextComponent>();
	if(text != nullptr)
		m_FPSText->GetComponent<TextComponent>()->SetText(std::move(std::to_string(int(1.f / elapsedSec))));

	glm::vec3 pos = m_Logo->GetTransform().GetPosition();
	pos.x += 70 * elapsedSec;
	if (pos.x > 1280.f)
	{
		pos.x = 0.f;
	}
	m_Logo->GetTransform().SetPosition(pos);
}

void dae::TestScene::Render() const
{
}

#include "pch.h"
#include "TestScene.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "Transform.h"
#include "RenderComponent.h"
#include "SceneRenderer.h"
#include "TextComponent.h"
#include "GameTime.h"
#include "KeyboardInputComponent.h"
#include "ControllerInputComponent.h"

dae::TestScene::TestScene()
	: Scene(std::move("TestScene"))
{
}

void dae::TestScene::Initialize()
{
	auto obj = std::make_shared<GameObject>();
	TextureComponent* texComp = new TextureComponent(obj);
	texComp->SetTexture(std::move("background.jpg"));

	texComp->SetDestRect({ 0,0 }, 640.f, 480.f);
	obj->AddComponent(texComp);

	AddGameObject(obj);

	obj = std::make_shared<GameObject>();
	texComp = new TextureComponent(obj);
	texComp->SetTexture(std::move("logo.png"));
	glm::vec2 texDim = texComp->GetTextureSizes();
	obj->AddComponent(texComp);
	obj->GetTransform().SetPosition( 640.f / 2 - texDim.x / 2, 480.f / 2 - texDim.y / 2 ,0 );
	ControllerInputComponent* input = new ControllerInputComponent(obj);
	input->AddInputAction({ std::make_shared<MoveRightCommand>(),ControllerButton::ArrowRight });
	obj->AddComponent(input);
	m_Logo = obj;
	AddGameObject(obj);

	obj = std::make_shared<GameObject>();
	texComp = new TextureComponent(obj);
	obj->AddComponent(texComp);
	TextComponent *textComp = new TextComponent(obj);
	textComp->SetFont(std::move("Lingua.otf"));
	textComp->SetText(std::move(std::to_string(100)));
	textComp->SetColor({ 0,255,0,255 });
	obj->AddComponent(textComp);
	KeyboardInputComponent* keyInput = new KeyboardInputComponent(obj);
	keyInput->AddInputAction({ std::make_shared<MoveRightCommand>(), SDLK_d });
	obj->AddComponent(keyInput);
	m_FPSText = obj;
	AddGameObject(obj);

	
}

void dae::TestScene::Update()
{
	float elapsedSec = GameTime::GetInstance().GetElapsedSec();
	TextComponent *text = m_FPSText->GetComponent<TextComponent>();
	if(text != nullptr)
		m_FPSText->GetComponent<TextComponent>()->SetText(std::move(std::to_string(int(1.f / elapsedSec))));
}

void dae::TestScene::Render() const
{
}

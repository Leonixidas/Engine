#include "pch.h"
#include "StartScreen.h"
#include <GameObject.h>
#include <TextComponent.h>
#include <TextureComponent.h>
#include <Transform.h>
#include <InputManager.h>
#include <GameTime.h>
#include <SceneManager.h>


imp::StartScreen::StartScreen(MiniginGame* game)
	: Scene("StartScreen")
	, m_pGame(game)
{
}

void imp::StartScreen::Initialize()
{
	//SINGLEPLAYER
	auto obj = std::make_shared<GameObject>();
	m_Objects.push_back(obj);

	auto textureComp = new TextureComponent(obj);
	obj->AddComponent(textureComp);

	auto textComp = new TextComponent(obj);
	textComp->SetColor({ 255,255,0,255 });
	textComp->SetText(std::move("SinglePlayer"));
	textComp->SetSize(36);
	obj->AddComponent(textComp);

	glm::vec2 halfsize = { float(textureComp->GetDestRect().w) * 0.5f, float(textureComp->GetDestRect().h)};
	float offset = 30.f;
	obj->GetTransform().SetPosition(640.f / 2.f - halfsize.x, 480.f / 2.f - (offset + halfsize.y), 0.f);

	AddGameObject(obj);

	//MULTIPLAYER
	obj = std::make_shared<GameObject>();
	m_Objects.push_back(obj);

	textureComp = new TextureComponent(obj);
	obj->AddComponent(textureComp);

	textComp = new TextComponent(obj);
	textComp->SetText(std::move("MultiPlayer"));
	obj->AddComponent(textComp);

	halfsize = { float(textureComp->GetDestRect().w) * 0.5f, float(textureComp->GetDestRect().h) * 0.5f };
	obj->GetTransform().SetPosition(640.f / 2.f - halfsize.x, 480.f / 2.f - halfsize.y, 0.f);

	AddGameObject(obj);

	//EXIT
	obj = std::make_shared<GameObject>();
	m_Objects.push_back(obj);

	textureComp = new TextureComponent(obj);
	obj->AddComponent(textureComp);

	textComp = new TextComponent(obj);
	textComp->SetText(std::move("Exit"));
	obj->AddComponent(textComp);

	halfsize = { float(textureComp->GetDestRect().w) * 0.5f, float(textureComp->GetDestRect().h) };
	obj->GetTransform().SetPosition(640.f / 2.f - halfsize.x, 480.f / 2.f + halfsize.y, 0.f);

	AddGameObject(obj);

	obj = std::make_shared<GameObject>();
	textureComp = new TextureComponent(obj);
	obj->AddComponent(textureComp);
	textComp = new TextComponent(obj);
	textComp->SetFont(std::move("Lingua.otf"));
	textComp->SetText(std::move(std::to_string(100)));
	textComp->SetColor({ 0,255,0,255 });
	obj->AddComponent(textComp);
	m_FPSText = obj;
	AddGameObject(obj);

}

void imp::StartScreen::Update()
{
	float avg = GameTime::GetInstance().GetFPS();
	avg = float(int(avg * 100)) / 100.f;
	TextComponent *text = m_FPSText->GetComponent<TextComponent>();
	if (text != nullptr)
		m_FPSText->GetComponent<TextComponent>()->SetText(std::move(std::to_string(avg).substr(0,5)));

	//Changing the selected button on the screen
	//******************************************
	if (InputManager::GetInstance().IsPressed(ControllerButton::ArrowDown, 0) ||
		InputManager::GetInstance().IsPressed(SDLK_DOWN) ||
		InputManager::GetInstance().IsPressed(SDLK_s))
	{
		DeselectObject();

		++m_objectIndex;
		if (m_objectIndex >= m_Objects.size())
			m_objectIndex = 0;
		
		SelectObject();
	}
	else if (InputManager::GetInstance().IsPressed(ControllerButton::ArrowUp, 0) ||
			 InputManager::GetInstance().IsPressed(SDLK_UP) ||
			 InputManager::GetInstance().IsPressed(SDLK_w))
	{
		DeselectObject();

		--m_objectIndex;
		if (m_objectIndex < 0)
			m_objectIndex = int(m_Objects.size() - 1);

		SelectObject();
	}

	//Checking which button is pressed in the startscreen
	//***************************************************
	if (InputManager::GetInstance().IsPressed(ControllerButton::ButtonA, 0) ||
		InputManager::GetInstance().IsPressed(SDLK_RETURN) ||
		InputManager::GetInstance().IsPressed(SDLK_RETURN2))
	{
		if (m_objectIndex == 0)
			SceneManager::GetInstance().SetActiveScene(std::move("SinglePlay"));
		else if (m_objectIndex == 1)
			SceneManager::GetInstance().SetActiveScene(std::move("MultiplayerScreen"));
		else
			m_pGame->SetGameState(GameStates::EXITING);
		
		DeselectObject();
		m_objectIndex = 0;
		SelectObject();
	}
}

void imp::StartScreen::Render() const
{
}

void imp::StartScreen::DeselectObject()
{
	auto obj = m_Objects[m_objectIndex];
	auto textComp = obj->GetComponent<TextComponent>();
	auto textureComp = obj->GetComponent<TextureComponent>();

	textComp->SetColor({ 255,255,255,255 });
	textComp->SetSize(24);

	glm::vec2 halfsize = { float(textureComp->GetDestRect().w) * 0.5f, float(textureComp->GetDestRect().h) };

	if (m_objectIndex - 1 == 0)
	{
		halfsize.y *= 0.5f;
		obj->GetTransform().SetPosition(640.f / 2.f - halfsize.x, 480.f / 2.f - halfsize.y, 0.f);
	}
	else if(m_objectIndex - 1 < 0)
	{
		float offset = 30.f;
		obj->GetTransform().SetPosition(640.f / 2.f - halfsize.x, 480.f / 2.f - (offset + halfsize.y), 0.f);
	}
	else
	{
		obj->GetTransform().SetPosition(640.f / 2.f - halfsize.x, 480.f / 2.f + (halfsize.y), 0.f);
	}
}

void imp::StartScreen::SelectObject()
{
	auto obj = m_Objects[m_objectIndex];
	auto textComp = obj->GetComponent<TextComponent>();
	auto textureComp = obj->GetComponent<TextureComponent>();

	textComp->SetColor({ 255,255,0,255 });
	textComp->SetSize(36);

	glm::vec2 halfsize = { float(textureComp->GetDestRect().w) * 0.5f, float(textureComp->GetDestRect().h) };
	float offset = 30.f;

	if (m_objectIndex - 1 == 0)
	{
		halfsize.y *= 0.5f;
		obj->GetTransform().SetPosition(640.f / 2.f - halfsize.x, 480.f / 2.f - halfsize.y, 0.f);
	}
	else if (m_objectIndex - 1 < 0)
	{
		obj->GetTransform().SetPosition(640.f / 2.f - halfsize.x, 480.f / 2.f - (offset + halfsize.y), 0.f);
	}
	else
	{
		obj->GetTransform().SetPosition(640.f / 2.f - halfsize.x, 480.f / 2.f + halfsize.y, 0.f);
	}
}

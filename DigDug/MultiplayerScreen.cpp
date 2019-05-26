#include "pch.h"
#include "MultiplayerScreen.h"
#include <GameObject.h>
#include <TextComponent.h>
#include <TextureComponent.h>
#include <Transform.h>
#include <InputManager.h>
#include <GameTime.h>
#include <SceneManager.h>
#include "DigDugEnums.h"


imp::MultiplayerScreen::MultiplayerScreen(const std::shared_ptr<MiniginGame>& game)
	: Scene(std::move("MultiplayerScreen"), game)
{
}

void imp::MultiplayerScreen::Initialize()
{
	glm::vec2 gameSize = m_pGame->GetWindowDimensions();

	//COOP
	auto obj = std::shared_ptr<GameObject>(new GameObject());
	m_Objects.push_back(obj);

	auto textureComp = new TextureComponent(obj);
	obj->AddComponent(textureComp);

	auto textComp = new TextComponent(obj);
	textComp->SetColor({ 255,255,0,255 });
	textComp->SetText(std::move("CO-OP"));
	textComp->SetSize(36);
	obj->AddComponent(textComp);

	glm::vec2 halfsize = { float(textureComp->GetDestRect().w) * 0.5f, float(textureComp->GetDestRect().h) };
	float offset = 30.f;
	obj->GetTransform().SetPosition(gameSize.x / 2.f - halfsize.x, gameSize.y / 2.f - (offset + halfsize.y), 0.f);

	AddGameObject(obj);

	//VERSUS
	obj = std::shared_ptr<GameObject>(new GameObject());
	m_Objects.push_back(obj);

	textureComp = new TextureComponent(obj);
	obj->AddComponent(textureComp);

	textComp = new TextComponent(obj);
	textComp->SetText(std::move("VERSUS"));
	obj->AddComponent(textComp);

	halfsize = { float(textureComp->GetDestRect().w) * 0.5f, float(textureComp->GetDestRect().h) * 0.5f };
	obj->GetTransform().SetPosition(gameSize.x / 2.f - halfsize.x, gameSize.y / 2.f - halfsize.y, 0.f);

	AddGameObject(obj);

	//BACK
	obj = std::shared_ptr<GameObject>(new GameObject());
	m_Objects.push_back(obj);

	textureComp = new TextureComponent(obj);
	obj->AddComponent(textureComp);

	textComp = new TextComponent(obj);
	textComp->SetText(std::move("Back"));
	obj->AddComponent(textComp);

	halfsize = { float(textureComp->GetDestRect().w) * 0.5f, float(textureComp->GetDestRect().h) };
	obj->GetTransform().SetPosition(gameSize.x / 2.f - halfsize.x, gameSize.y / 2.f + halfsize.y, 0.f);

	AddGameObject(obj);

	//FPS
	obj = std::shared_ptr<GameObject>(new GameObject());
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

void imp::MultiplayerScreen::Update()
{
	float avg = GameTime::GetInstance().GetFPS();
	avg = float(int(avg * 100)) / 100.f;
	TextComponent *text = m_FPSText->GetComponent<TextComponent>();
	if (text != nullptr)
		m_FPSText->GetComponent<TextComponent>()->SetText(std::move(std::to_string(avg).substr(0, 4)));

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

	if (InputManager::GetInstance().IsPressed(ControllerButton::ButtonA, 0) ||
		InputManager::GetInstance().IsPressed(SDLK_RETURN) ||
		InputManager::GetInstance().IsPressed(SDLK_RETURN2))
	{
		if (m_objectIndex == 0)
		{
			m_pGame->SetGameMode(int(DigDugGameModes::MULTIPLAYER_COOP));
			SceneManager::GetInstance().SetActiveScene(std::move("Level1"));
		}
		else if (m_objectIndex == 1)
		{
			m_pGame->SetGameMode(int(DigDugGameModes::MULTIPLAYER_COOP));
			SceneManager::GetInstance().SetActiveScene(std::move("VersusLevel1"));
		}
		else
			SceneManager::GetInstance().GoToPreviousScene();

		DeselectObject();
		m_objectIndex = 0;
		SelectObject();
	}
}

void imp::MultiplayerScreen::Render() const
{
}

void imp::MultiplayerScreen::DeselectObject()
{
	glm::vec2 gameSize = m_pGame->GetWindowDimensions();

	auto obj = m_Objects[m_objectIndex];
	auto textComp = obj->GetComponent<TextComponent>();
	auto textureComp = obj->GetComponent<TextureComponent>();

	textComp->SetColor({ 255,255,255,255 });
	textComp->SetSize(24);

	glm::vec2 halfsize = { float(textureComp->GetDestRect().w) * 0.5f, float(textureComp->GetDestRect().h) };

	if (m_objectIndex - 1 == 0)
	{
		halfsize.y *= 0.5f;
		obj->GetTransform().SetPosition(gameSize.x / 2.f - halfsize.x, gameSize.y / 2.f - halfsize.y, 0.f);
	}
	else if (m_objectIndex - 1 < 0)
	{
		float offset = 30.f;
		obj->GetTransform().SetPosition(gameSize.x / 2.f - halfsize.x, gameSize.y / 2.f - (offset + halfsize.y), 0.f);
	}
	else
	{
		obj->GetTransform().SetPosition(gameSize.x / 2.f - halfsize.x, gameSize.y / 2.f + (halfsize.y), 0.f);
	}
}

void imp::MultiplayerScreen::SelectObject()
{
	glm::vec2 gameSize = m_pGame->GetWindowDimensions();

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
		obj->GetTransform().SetPosition(gameSize.x / 2.f - halfsize.x, gameSize.y / 2.f - halfsize.y, 0.f);
	}
	else if (m_objectIndex - 1 < 0)
	{
		obj->GetTransform().SetPosition(gameSize.x / 2.f - halfsize.x, gameSize.y / 2.f - (offset + halfsize.y), 0.f);
	}
	else
	{
		obj->GetTransform().SetPosition(gameSize.x / 2.f - halfsize.x, gameSize.y / 2.f + halfsize.y, 0.f);
	}
}

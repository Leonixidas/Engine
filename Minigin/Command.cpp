#include "MiniginPCH.h"
#include "Command.h"
#include "GameObject.h"
#include "Transform.h"
#include "PlayerComponent.h"
#include "GameTime.h"
#include "Enums.h"

void imp::ShootCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	if (affected != nullptr)
	{
		auto playerComp = affected->GetComponent<PlayerComponent>();

		if (playerComp != nullptr)
			playerComp->SetPlayerState(PlayerState::SHOOTING);
	}
}

void imp::MoveLeftCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	if (affected != nullptr)
	{
		auto playerComp = affected->GetComponent<PlayerComponent>();

		if (playerComp != nullptr)
		{
			playerComp->SetPlayerState(PlayerState::RUNNING);
			playerComp->SetPlayerDirection(Direction::FACE_LEFT);

		}

		Transform& t = affected->GetTransform();
		glm::vec3 pos = t.GetPosition();
		pos.x -= 200 * GameTime::GetInstance().GetElapsedSec();
		t.SetPosition(pos);
	}
}

void imp::MoveRightCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	if (affected != nullptr)
	{
		auto playerComp = affected->GetComponent<PlayerComponent>();

		if (playerComp != nullptr)
		{
			playerComp->SetPlayerState(PlayerState::RUNNING);
			playerComp->SetPlayerDirection(Direction::FACE_RIGHT);
		}

		Transform& t = affected->GetTransform();
		glm::vec3 pos = t.GetPosition();
		pos.x += 200 * GameTime::GetInstance().GetElapsedSec();
		t.SetPosition(pos);
	}
}

void imp::MoveUpCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	if (affected != nullptr)
	{
		auto playerComp = affected->GetComponent<PlayerComponent>();

		if (playerComp != nullptr)
		{
			playerComp->SetPlayerState(PlayerState::RUNNING);
			playerComp->SetPlayerDirection(Direction::FACE_UP);
		}

		Transform& t = affected->GetTransform();
		glm::vec3 pos = t.GetPosition();
		pos.y -= 200 * GameTime::GetInstance().GetElapsedSec();
		t.SetPosition(pos);
	}
}

void imp::MoveDownCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	if (affected != nullptr)
	{
		auto playerComp = affected->GetComponent<PlayerComponent>();

		if (playerComp != nullptr)
		{
			playerComp->SetPlayerState(PlayerState::RUNNING);
			playerComp->SetPlayerDirection(Direction::FACE_DOWN);
		}

		Transform& t = affected->GetTransform();
		glm::vec3 pos = t.GetPosition();
		pos.y += 200 * GameTime::GetInstance().GetElapsedSec();
		t.SetPosition(pos);
	}
}

void imp::PumpCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	if (affected != nullptr)
	{
		auto playerComp = affected->GetComponent<PlayerComponent>();

		if (playerComp != nullptr)
			playerComp->SetPlayerState(PlayerState::PUMPING);
	}
}


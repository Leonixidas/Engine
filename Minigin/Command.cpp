#include "MiniginPCH.h"
#include "Command.h"
#include "GameObject.h"
#include "Transform.h"
#include "GameTime.h"

void dae::ShootCommand::Execute(std::shared_ptr<GameObject>&)
{
}

void dae::MoveLeftCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	Transform& t = affected->GetTransform();
	glm::vec3 pos = t.GetPosition();
	pos.x -= 200 * GameTime::GetInstance().GetElapsedSec();
	t.SetPosition(pos);
}

void dae::MoveRightCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	Transform& t = affected->GetTransform();
	glm::vec3 pos = t.GetPosition();
	pos.x += 200 * GameTime::GetInstance().GetElapsedSec();
	t.SetPosition(pos);
}

void dae::MoveUpCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	Transform& t = affected->GetTransform();
	glm::vec3 pos = t.GetPosition();
	pos.y -= 200 * GameTime::GetInstance().GetElapsedSec();
	t.SetPosition(pos);
}

void dae::MoveDownCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	Transform& t = affected->GetTransform();
	glm::vec3 pos = t.GetPosition();
	pos.y += 200 * GameTime::GetInstance().GetElapsedSec();
	t.SetPosition(pos);
}

void dae::PumpCommand::Execute(std::shared_ptr<GameObject>&)
{
}

#include "MiniginPCH.h"
#include "Command.h"
#include "GameObject.h"
#include "Transform.h"
#include "GameTime.h"

void imp::ShootCommand::Execute(std::shared_ptr<GameObject>&)
{
}

void imp::MoveLeftCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	Transform& t = affected->GetTransform();
	glm::vec3 pos = t.GetPosition();
	pos.x -= 200 * GameTime::GetInstance().GetElapsedSec();
	t.SetPosition(pos);
}

void imp::MoveRightCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	Transform& t = affected->GetTransform();
	glm::vec3 pos = t.GetPosition();
	pos.x += 200 * GameTime::GetInstance().GetElapsedSec();
	t.SetPosition(pos);
}

void imp::MoveUpCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	Transform& t = affected->GetTransform();
	glm::vec3 pos = t.GetPosition();
	pos.y -= 200 * GameTime::GetInstance().GetElapsedSec();
	t.SetPosition(pos);
}

void imp::MoveDownCommand::Execute(std::shared_ptr<GameObject>& affected)
{
	Transform& t = affected->GetTransform();
	glm::vec3 pos = t.GetPosition();
	pos.y += 200 * GameTime::GetInstance().GetElapsedSec();
	t.SetPosition(pos);
}

void imp::PumpCommand::Execute(std::shared_ptr<GameObject>&)
{
}

void imp::QuitCommand::Execute()
{
	
}

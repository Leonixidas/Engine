#include "pch.h"
#include "Level2.h"
#include <istream>
#include <fstream>
#include <iostream>
#include <string>
#include <MiniginGame.h>
#include "TextureComponent.h"
#include "Transform.h"
#include "GameObject.h"
#include "PlayerComponent.h"
#include "AnimatorComponent.h"
#include "ColliderComponent.h"
#include "ScoreComponent.h"
#include "ControllerInputDevice.h"
#include "DigDugEnums.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TextComponent.h"
#include "GameTime.h"
#include "Command.h"


imp::Level2::Level2(const std::shared_ptr<MiniginGame>& game)
	:Scene(std::move("Level2"), game)
{
}

void imp::Level2::Initialize()
{
	LoadLevel();

	//FPS
	auto obj = std::shared_ptr<GameObject>(new GameObject());
	auto textureComp = new TextureComponent(obj);
	obj->AddComponent(textureComp);
	auto textComp = new TextComponent(obj);
	textComp->SetFont(std::move("Lingua.otf"));
	textComp->SetText(std::move(std::to_string(100)));
	textComp->SetColor({ 0,255,0,255 });
	obj->AddComponent(textComp);
	m_FPSText = obj;
	AddGameObject(obj);
}

void imp::Level2::Update()
{
	float avg = GameTime::GetInstance().GetFPS();
	avg = float(int(avg * 100)) / 100.f;
	TextComponent *text = m_FPSText->GetComponent<TextComponent>();
	if (text != nullptr)
		m_FPSText->GetComponent<TextComponent>()->SetText(std::move(std::to_string(avg).substr(0, 4)));
}

void imp::Level2::Render() const
{
}

void imp::Level2::LoadLevel()
{
	std::ifstream input{};

	input.open(std::move("../Data/Level2.txt"));

	if (input.fail())
	{
		std::cout << "Failed to generate level -> Level1.txt does not exist\n";
		return;
	}

	int counter{};

	std::string inputString{};
	std::string temp{};
	size_t row{}, colum{}, pos{}, pos1{};
	size_t w{}, h{};
	while (std::getline(input, inputString))
	{
		if (inputString.find("Player") != std::string::npos)
		{
			if (counter == 0)
			{
				pos = inputString.find_first_of('>') + 1;
				pos1 = inputString.find_last_of('<');
				size_t first = inputString.find_first_of(',');
				colum = size_t(std::stoi(inputString.substr(pos, first++)));
				row = size_t(std::stoi(inputString.substr(first, pos1)));

				CreatePlayer(colum, row);
				++counter;
			}
			else if (counter > 0 && DigDugGameModes(m_pGame->GetGameMode()) != DigDugGameModes::SINGLEPLAYER)
			{
				pos = inputString.find_first_of('>') + 1;
				pos1 = inputString.find_last_of('<');
				size_t first = inputString.find_first_of(',');
				colum = size_t(std::stoi(inputString.substr(pos, first++)));
				row = size_t(std::stoi(inputString.substr(first, pos1)));

				CreatePlayer(colum, row);
			}
		}
		else if (inputString.find("Fygar") != std::string::npos)
		{
			pos = inputString.find_first_of('>') + 1;
			pos1 = inputString.find_last_of('<');
			size_t first = inputString.find_first_of(',');
			colum = size_t(std::stoi(inputString.substr(pos, first++)));
			row = size_t(std::stoi(inputString.substr(first, pos1)));

			CreateFygar(colum, row);
		}
		else if (inputString.find("Pooka") != std::string::npos)
		{
			pos = inputString.find_first_of('>') + 1;
			pos1 = inputString.find_last_of('<');
			size_t first = inputString.find_first_of(',');
			colum = size_t(std::stoi(inputString.substr(pos, first++)));
			row = size_t(std::stoi(inputString.substr(first, pos1)));

			CreatePooka(colum, row);
		}
		else if (inputString.find("Grid") != std::string::npos)
		{
			pos = inputString.find_first_of('>') + 1;
			pos1 = inputString.find_last_of('<');
			size_t first = inputString.find_first_of(',');
			size_t second = inputString.find_first_of(',', first + 1);
			size_t third = inputString.find_last_of(',');

			colum = size_t(std::stoi(inputString.substr(pos, first++)));
			row = size_t(std::stoi(inputString.substr(first, second++)));
			w = size_t(std::stoi(inputString.substr(second, third++)));
			h = size_t(std::stoi(inputString.substr(third, pos1)));
		}
		else if (inputString.find("FreeSpace") != std::string::npos)
		{
			size_t first{};
			std::vector<size_t> freeSpaces{};

			pos = inputString.find_first_of('>');
			pos1 = inputString.find_last_of('<');
			first = inputString.find_first_of(',', pos);

			while (pos != pos1)
			{
				++pos;
				first = inputString.find_first_of(',', pos);
				freeSpaces.push_back(size_t(std::stoi(inputString.substr(pos, first++))));
				pos = first;
				first = inputString.find_first_of(',', pos);
				if (first != std::string::npos)
				{
					freeSpaces.push_back(size_t(std::stoi(inputString.substr(pos, first))));
					pos = first;
				}
				else
				{
					freeSpaces.push_back(size_t(std::stoi(inputString.substr(pos, pos1))));
					pos = pos1;
				}
			}
			CreateGrid(colum, row, w, h, freeSpaces);
		}
	}

	input.close();
}

void imp::Level2::CreatePlayer(size_t colum, size_t row)
{
	auto player = std::shared_ptr<GameObject>(new GameObject());
	player->GetTransform().SetPosition(colum * 32.f, (640.f - 596.f) + (row * 32.f), 0.f);
	auto texComp = new TextureComponent(player);
	texComp->SetTexture("SpriteSheet.png");
	auto playerComp = new PlayerComponent(player);
	auto scoreComp = new ScoreComponent(player);
	auto animComp = new AnimatorComponent(player);

	std::ifstream input;
	input.open("../Data/AnimClipsPlayer.txt");

	if (input.fail())
	{
		std::cout << "Player creation failed -> Animation clip file not found\n";
		return;
	}

	size_t pos{}, pos1{};
	std::string state{ std::move("state=") };
	std::string dir{ std::move("direction=") };
	std::string frameCount{ std::move("framecount=") };
	std::string size{ std::move("size=") };
	std::string frameTime{ std::move("frametime=") };
	std::string animSpeed{ std::move("animspeed=") };
	std::string texPos{ std::move("pos=") };

	std::string inputString{};

	int s{}, d{}, f{};
	glm::vec2 texSize{}, texP{};
	float frameT{}, animS{};

	while (std::getline(input, inputString))
	{
		pos = inputString.find(state) + state.length();
		pos1 = inputString.find(',');
		s = std::stoi(inputString.substr(pos, pos1 - pos));

		pos = inputString.find(dir) + dir.length();
		pos1 = inputString.find(',', pos);
		d = std::stoi(inputString.substr(pos, pos1 - pos));

		pos = inputString.find(frameCount) + frameCount.length();
		pos1 = inputString.find(',', pos);
		f = std::stoi(inputString.substr(pos, pos1 - pos));

		pos = inputString.find(size) + size.length();
		pos1 = inputString.find('.', pos);
		texSize.x = std::stof(inputString.substr(pos, pos1 - pos));
		pos = pos1 + 1;
		pos1 = inputString.find(',', pos);
		texSize.y = std::stof(inputString.substr(pos, pos1 - pos));

		pos = inputString.find(frameTime) + frameTime.length();
		pos1 = inputString.find(',', pos);
		frameT = std::stof(inputString.substr(pos, pos1 - pos));

		pos = inputString.find(animSpeed) + animSpeed.length();
		pos1 = inputString.find(',', pos);
		animS = std::stof(inputString.substr(pos, pos1 - pos));

		pos = inputString.find(texPos) + texPos.length();
		pos1 = inputString.find('.', pos);
		texP.x = std::stof(inputString.substr(pos, pos1 - pos));
		pos = pos1 + 1;
		pos1 = inputString.find(',', pos);
		texP.y = std::stof(inputString.substr(pos, pos1 - pos));

		animComp->AddAnimationClip(std::shared_ptr<AnimationClip>(new AnimationClip{ s,d,f,texSize,frameT,animS,texP }));
	}

	auto controller = playerComp->GetKeyboardInput();
	controller->AddInputAction({ std::shared_ptr<MoveRightCommand>(new MoveRightCommand()),SDLK_d, player });
	controller->AddInputAction({ std::shared_ptr<MoveLeftCommand>(new MoveLeftCommand()),SDLK_a, player });
	controller->AddInputAction({ std::shared_ptr<MoveDownCommand>(new MoveDownCommand()),SDLK_s, player });
	controller->AddInputAction({ std::shared_ptr<MoveUpCommand>(new MoveUpCommand()),SDLK_w, player });


	player->AddComponent(texComp);
	player->AddComponent(playerComp);
	player->AddComponent(scoreComp);
	player->AddComponent(animComp);
	AddGameObject(player);

	input.close();
}

void imp::Level2::CreatePooka(size_t , size_t )
{
}

void imp::Level2::CreateFygar(size_t , size_t )
{
}

void imp::Level2::CreateGrid(size_t colum, size_t row, size_t w, size_t h, const std::vector<size_t>& freeSpaces)
{
	for (size_t i = 0, size = colum * row; i < size; ++i)
	{
		if (std::find(freeSpaces.begin(), freeSpaces.end(), i) == freeSpaces.end())
		{
			auto tile = std::shared_ptr<GameObject>(new GameObject());
			auto texComp = new TextureComponent(tile);
			texComp->SetTexture(std::move("default_dirt.png"));
			tile->GetTransform().SetPosition(float(w) * (i % colum), 640.f - 596.f + float(h) * (i / colum), 0.f);
			tile->AddComponent(std::move(texComp));
			AddGameObject(tile);
		}
	}
}

#pragma once

namespace dae
{
	class GameObject;

	class Command
	{
	public:
		Command() = default;
		virtual ~Command() = default;

		virtual void Execute(std::shared_ptr<GameObject>& ) {};
	};

	class ShootCommand final : public Command
	{
	public:
		ShootCommand() = default;
		~ShootCommand() = default;
		virtual void Execute(std::shared_ptr<GameObject>&) override;
	};

	class MoveLeftCommand final : public Command
	{
	public:
		MoveLeftCommand() = default;
		~MoveLeftCommand() = default;
		virtual void Execute(std::shared_ptr<GameObject>& affected) override;
	};

	class MoveRightCommand final : public Command
	{
	public:
		MoveRightCommand() = default;
		~MoveRightCommand() = default;
		virtual void Execute(std::shared_ptr<GameObject>& affected) override;
	};

	class MoveUpCommand final : public Command
	{
	public:
		MoveUpCommand() = default;
		~MoveUpCommand() = default;
		virtual void Execute(std::shared_ptr<GameObject>&) override;
	};

	class MoveDownCommand final : public Command
	{
	public:
		MoveDownCommand() = default;
		~MoveDownCommand() = default;
		virtual void Execute(std::shared_ptr<GameObject>&) override;
	};


	class PumpCommand final : public Command
	{
	public:
		PumpCommand() = default;
		~PumpCommand() = default;
		virtual void Execute(std::shared_ptr<GameObject>&) override;
	};

	class QuitCommand final : public Command
	{
	public:
		QuitCommand() = default;
		~QuitCommand() = default;
		void Execute();
	};
}

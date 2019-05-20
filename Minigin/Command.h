#pragma once

namespace dae
{
	class Command
	{
	public:
		Command() = default;
		virtual ~Command() = default;

		virtual void Execute() = 0;
	};

	class ShootCommand final : public Command
	{
	public:
		ShootCommand() = default;
		~ShootCommand() = default;
		virtual void Execute() override {}
	};

	class MoveLeftCommand final : public Command
	{
		MoveLeftCommand() = default;
		~MoveLeftCommand() = default;
		virtual void Execute() override {}
	};

	class MoveRightCommand final : public Command
	{
		MoveRightCommand() = default;
		~MoveRightCommand() = default;
		virtual void Execute() override {}
	};

	class MoveUpCommand final : public Command
	{
		MoveUpCommand() = default;
		~MoveUpCommand() = default;
		virtual void Execute() override {}
	};

	class MoveDownCommand final : public Command
	{
		MoveDownCommand() = default;
		~MoveDownCommand() = default;
		virtual void Execute() override {}
	};


	class PumpCommand final : public Command
	{
		PumpCommand() = default;
		~PumpCommand() = default;
		virtual void Execute() override {}
	};
}

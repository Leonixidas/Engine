#pragma once
#include <Scene.h>

namespace imp
{
	class Level2 : public Scene
	{
	public:
		Level2(const std::shared_ptr<MiniginGame>& game);
		~Level2() = default;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render() const override;

	private:
		void LoadLevel();
		void CreatePlayer(size_t colum, size_t row);
		void CreatePooka(size_t colum, size_t row);
		void CreateFygar(size_t colum, size_t row);
		void CreateGrid(size_t colum, size_t row, size_t w, size_t h, const std::vector<size_t>& freeSpaces);

		std::shared_ptr<GameObject> m_FPSText;
	};
}


#include "BaseComponent.h"

namespace dae
{
	class Transform final
	{
		glm::vec3 m_Position{};
	public:
		Transform() = default;
		~Transform() = default;
		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z);
		void SetPosition(const glm::vec3& pos);
	};
}

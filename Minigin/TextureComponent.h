#pragma once
#include "BaseComponent.h"
#include "Texture2D.h"

namespace dae
{
	class TextureComponent final : public BaseComponent
	{
	public:
	public:
		TextureComponent(const std::shared_ptr<GameObject>& owner);
		~TextureComponent() = default;

		virtual void Update(float elapsedSec) override;
		virtual void Render() const override;

		void SetTexture(const std::string& assetFile);
		void SetWidthAndHeight(const float& width, const float& height);

	private:
		std::shared_ptr<Texture2D> m_pTexture;
		float m_Width;
		float m_Height;
	};
}


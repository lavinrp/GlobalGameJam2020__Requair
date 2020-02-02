
#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/GameObjects/SpriteItem.h>

#include <SFML/Graphics/Texture.hpp>


namespace REQ
{
	class libRequair Key : public SpriteItem
	{
	public:
		Key(float x, float y);

		void Interact(REQ::Boss& boss) override;

		bool IsCollectible() override;

	private:
		sf::Texture m_texture = []() {
			sf::Texture tex{};
			tex.loadFromFile("Textures/Key.png");
			return tex;
		}();
	};

}